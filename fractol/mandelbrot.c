/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:59:09 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:05:21 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	For information:
**	The original formulae with no user zoom and no offset is :
**		zoom_x = WIN_W / (X2 - X1);
**		zoom_y = WIN_H / (Y2 - Y1);
**		c_r = (double)x / zoom_x + X1;
**		c_i = (double)y / zoom_y + Y1;
*/

t_iter	mandelbrot(int x, int y, t_env w)
{
	t_calc	d;
	t_iter	ret;

	d.zoom_x = w.d_zoom_x;
	d.zoom_y = w.d_zoom_y;
	d.c_r = ((double)x - w.center_x) / d.zoom_x + X1 + w.offset_x;
	d.c_i = ((double)w.center_y - y) / d.zoom_y + Y1 + (w.offset_y);
	d.z_r = 0;
	d.z_i = 0;
	ret.i = 0;
	while (d.z_r * d.z_r + d.z_i * d.z_i < 4 && ret.i < w.itermax)
	{
		d.tmp = d.z_r;
		d.z_r = d.z_r * d.z_r - d.z_i * d.z_i + d.c_r;
		d.z_i = 2 * d.z_i * d.tmp + d.c_i;
		ret.i++;
	}
	ret.z = d.z_r * d.z_r + d.z_i * d.z_i;
	if (ret.z > 4.0)
		ret.z = 4.0;
	if (ret.z < 0.0)
		ret.z = 0.0;
	ret.color = 0;
	return (ret);
}
