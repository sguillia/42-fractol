/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:08:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:31:03 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef GPU

static void	throw_kernel(char *errmsg)
{
	ft_printf_fd(2, "%red;OpenCL: %s%;\n", errmsg);
	exit(1);
}

static void	set_kernel_args(t_cl *cl, t_env w)
{
	int		err;

	err = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->output);
	err |= clSetKernelArg(cl->kernel, 1, sizeof(double), &w.d_zoom_x);
	err |= clSetKernelArg(cl->kernel, 2, sizeof(double), &w.d_zoom_y);
	err |= clSetKernelArg(cl->kernel, 3, sizeof(int), &w.center_x);
	err |= clSetKernelArg(cl->kernel, 4, sizeof(int), &w.center_y);
	err |= clSetKernelArg(cl->kernel, 5, sizeof(double), &w.offset_x);
	err |= clSetKernelArg(cl->kernel, 6, sizeof(double), &w.offset_y);
	err |= clSetKernelArg(cl->kernel, 7, sizeof(int), &w.mouse_x);
	err |= clSetKernelArg(cl->kernel, 8, sizeof(int), &w.mouse_y);
	err |= clSetKernelArg(cl->kernel, 9, sizeof(char), &w.colorft_num);
	err |= clSetKernelArg(cl->kernel, 10, sizeof(int), &w.itermax);
	err |= clSetKernelArg(cl->kernel, 11, sizeof(char), &w.fractalft_num);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to set kernel arguments");
}

static void	set_cl_global(t_cl *cl)
{
	cl->global = WIN_W * WIN_H;
	if (cl->global % cl->local)
	{
		ft_printf_fd(2, "%red;Error: OpenCL will crash:\n");
		ft_printf_fd(2, "WIN_W * WIN_H must be a multiple of local: %d\n",
				cl->local);
		exit(1);
	}
}

void		draw_gpu_fractal(t_env w)
{
	int		err;
	t_cl	*cl;

	w.d_zoom_x = w.zoom_x * WIN_W / (X2 - X1);
	w.d_zoom_y = w.zoom_y * WIN_H / (Y2 - Y1);
	cl = &(w.e->cl);
	set_kernel_args(cl, w);
	err = clGetKernelWorkGroupInfo(cl->kernel, cl->device_id,
			CL_KERNEL_WORK_GROUP_SIZE, sizeof(cl->local), &cl->local, NULL);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to retrieve kernel work group info");
	set_cl_global(cl);
	err = clEnqueueNDRangeKernel(cl->commands, cl->kernel, 1, NULL,
			&cl->global, &cl->local, 0, NULL, NULL);
	if (err)
		throw_kernel("Failed to execute kernel !");
	clFinish(cl->commands);
	err = clEnqueueReadBuffer(cl->commands, cl->output, CL_TRUE,
			0, WIN_W * WIN_H * 4, w.img_addr, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		throw_kernel("Failed to read output array");
}

#endif
