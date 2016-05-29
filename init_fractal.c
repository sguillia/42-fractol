/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:06 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:36:53 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_hooks(t_env *w)
{
	mlx_expose_hook(w->win, expose_hook, w);
	mlx_mouse_hook(w->win, mouse_hook, w);
	mlx_hook(w->win, 2, 0, keypressed, w);
	mlx_hook(w->win, 3, 1, keyreleased, w);
	mlx_hook(w->win, 6, 1 << 6, motion_hook, w);
}

static int	get_fractalft_num(t_env *w)
{
	if (w->fractalft == mandelbrot)
		return (1);
	else if (w->fractalft == julia)
		return (2);
	else
		return (3);
}

void		init_fractal(t_mlx *e, t_env *w)
{
	if (!(w->win = mlx_new_window(e->mlx, WIN_W, WIN_H, TITLE)))
		exit_str("Failed to create new window");
	if (!(w->img_ptr = mlx_new_image(e->mlx, WIN_W, WIN_H)))
		exit_str("Failed to create new image");
	w->img_addr = mlx_get_data_addr(w->img_ptr, &w->bpp, &w->linesize,
			&w->endian);
	if (IS_GPU && (w->linesize != WIN_W * 4 || w->bpp != 32))
	{
		ft_printf_fd(2, "%sERROR:%; %red;Linesize and bpp are not as ",
				"\x1b[1;31m");
		ft_printf_fd(2, "expected in OpenCL init%;\n");
		ft_printf_fd(2, "%yellow;Expected : %d and %d\n", WIN_W * 4, 32);
		ft_printf_fd(2, "Received : %d and %d\n", w->linesize, w->bpp);
		exit(1);
	}
	set_hooks(w);
	w->e = e;
	ft_bzero(w->keys, KEYCODE_MAX);
	init_fractal_values(w);
	w->colorft = (w->fractalft != newton) ? DEFAULT_COLORFT : color5;
	w->colorft_num = (w->fractalft != newton) ? DEFAULT_COLORFT_NUM : 5;
	w->fractalft_num = get_fractalft_num(w);
	redraw_fractal(*w);
}
