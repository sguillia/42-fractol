/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:11:24 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:30:44 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef GPU

static int	try_opencl_init_next(t_cl *cl)
{
	char		buffer[10000];
	size_t		len;

	cl->err = clBuildProgram(cl->program, 0, NULL, NULL, NULL, NULL);
	if (cl->err != CL_SUCCESS)
	{
		cl->err = clGetProgramBuildInfo(cl->program, cl->device_id,
				CL_PROGRAM_BUILD_LOG, 10000, buffer, &len);
		if (cl->err == CL_SUCCESS)
			ft_printf_fd(2, "%red;Compiler error message :%;\n%s\n", buffer);
		else
		{
			ft_printf_fd(2, "%red;Error while retrieving compiler log%;\n");
			ft_printf_fd(2, "%red;Try increasing buffer size to 100 000%;\n");
		}
		return (-5);
	}
	cl->kernel = clCreateKernel(cl->program, "iterate", &cl->err);
	if (!cl->kernel || cl->err != CL_SUCCESS)
		return (-6);
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,
			WIN_H * WIN_W * 4, NULL, NULL);
	if (!cl->output)
		return (-7);
	return (0);
}

static int	try_opencl_init(t_mlx *e)
{
	static char	*kernel_source;
	t_cl		*cl;

	cl = &(e->cl);
	cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 1, &cl->device_id, NULL);
	if (cl->err != CL_SUCCESS)
		return (-1);
	cl->context = clCreateContext(0, 1, &cl->device_id, NULL, NULL, &cl->err);
	if (!cl->context)
		return (-2);
	cl->commands = clCreateCommandQueue(cl->context, cl->device_id, 0,
			&cl->err);
	if (!cl->commands)
		return (-3);
	kernel_source = load_gpu_sources();
	cl->program = clCreateProgramWithSource(cl->context, 1,
			(const char**)&kernel_source, NULL, &cl->err);
	if (!cl->program)
		return (-4);
	return (try_opencl_init_next(cl));
}

void		opencl_init(t_mlx *e)
{
	int	err;

	err = try_opencl_init(e);
	if (err == 0)
	{
		ft_printf("%green;OpenCL init succeeded%;\n");
		return ;
	}
	ft_printf("%red;OpenCL init failed (%d)%;\n", err);
	exit(1);
}

#endif
