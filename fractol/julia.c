/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:59:09 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:05:51 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_iter	julia(int x, int y, t_env w)
{
	t_calc	d;
	t_iter	ret;

	d.zoom_x = w.d_zoom_x;
	d.zoom_y = w.d_zoom_y;
	d.z_r = ((double)x - w.center_x) / d.zoom_x + X1 + w.offset_x;
	d.z_i = ((double)w.center_y - y) / d.zoom_y + Y1 + (w.offset_y);
	d.c_r = (double)w.mouse_x / 1000 - 1;
	d.c_i = (double)w.mouse_y / 400 - 1;
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
