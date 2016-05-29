/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:08:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:38:31 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_env w)
{
	int		x;
	int		y;
	t_iter	ret;

	w.d_zoom_x = w.zoom_x * WIN_W / (X2 - X1);
	w.d_zoom_y = w.zoom_y * WIN_H / (Y2 - Y1);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			ret = w.fractalft(x, y, w);
			mlx_pixel_put_img(&w, x, y, w.colorft(ret, w.itermax));
		}
	}
}

/*
**	This function is not used by the program and must be used by programmer
**	It outputs the fractal iterations to a text file so that FdF can read it
**	Text file must exist and have appropriate permissions
**	To avoid FdF lag, output's resolution can be lowered by increasing 'dd'
*/

void	draw_extern_fractal(t_env w)
{
	int		x;
	int		y;
	t_iter	ret;
	int		fd;
	int		dd;

	dd = 5;
	if ((fd = open("FOR_FDF", O_WRONLY | O_TRUNC)) == -1)
		return ;
	w.d_zoom_x = w.zoom_x * WIN_W / (X2 - X1);
	w.d_zoom_y = w.zoom_y * WIN_H / (Y2 - Y1);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			ret = w.fractalft(x, y, w);
			if ((y % dd) == 0 && (x % dd) == 0)
				ft_printf_fd(fd, "%d ", ret.i);
		}
		if ((y % dd) == 0)
			ft_printf_fd(fd, "\n");
	}
}
