/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:53:31 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:04:49 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	show_usage(void)
{
	ft_printf_fd(2, "Usage:\n");
	ft_printf_fd(2, "./fractol [-m | mandelbrot]\n");
	ft_printf_fd(2, "./fractol [-j | julia]\n");
	ft_printf_fd(2, "./fractol [-n | newton]\n");
	ft_printf_fd(2, "Multi-window (CPU) : ./fractol -m -j -n\n");
	ft_printf_fd(2, "Maximum 3 fractals in CPU mode, 1 in GPU mode\n");
	exit(1);
}

static void	print_device(void)
{
	ft_printf("%s%yellow;Using device : %s%;\n",
			"\x1b[1;33m",
			IS_GPU ? "GPU" : "CPU");
}

void		check_arguments(t_env *wins, int ac, char **av)
{
	int		i;

	print_device();
	wins[1].win = NULL;
	wins[2].win = NULL;
	i = 0;
	while (++i < ac)
	{
		if ((i == 4) || (IS_GPU && i == 2))
			show_usage();
		else if (!ft_strcmp(av[i], "-m") || !ft_strcmp(av[i], "mandelbrot"))
			wins[i - 1].fractalft = mandelbrot;
		else if (!ft_strcmp(av[i], "-j") || !ft_strcmp(av[i], "julia"))
			wins[i - 1].fractalft = julia;
		else if (!ft_strcmp(av[i], "-n") || !ft_strcmp(av[i], "newton"))
			wins[i - 1].fractalft = newton;
		else
			show_usage();
	}
	if (i == 1 && DEFAULT)
		wins[0].fractalft = DEFAULT;
	else if (i == 1)
		show_usage();
}
