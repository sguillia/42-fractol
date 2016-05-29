/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:59:09 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 23:23:02 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#if (defined UNDEFINED) && !defined GPU

static double	clamp_to_pct4(double input, double min, double max)
{
	(void)min;
	(void)max;
	return (input);
}

#else

static double	clamp_to_pct4(double input, double min, double max)
{
	if (input < min)
		input = min;
	else if (input > max)
		input = max;
	input -= min;
	input = input / (max - min);
	input *= 4.;
	return (input);
}

#endif

static int		get_color_indicator(double dcr, double dci, int i)
{
	if (dcr > 0.0)
		return (i % 64);
	else if ((dcr < -0.3) && (dci > 0.0))
		return ((i % 64) + 64);
	else
		return ((i % 64) + 128);
}

t_iter			newton(int x, int y, t_env w)
{
	t_calc	d;
	t_iter	ret;
	double	dd;

	d.zoom_x = w.d_zoom_x;
	d.zoom_y = w.d_zoom_y;
	d.c_r = ((double)x - w.center_x) / d.zoom_x + X1 + w.offset_x;
	d.c_i = ((double)w.center_y - y) / d.zoom_y + Y1 + (w.offset_y);
	ret.i = 0;
	while (ret.i < w.itermax)
	{
		d.z_r = d.c_r * d.c_r;
		d.z_i = d.c_i * d.c_i;
		dd = 3.0 * ((d.z_r - d.z_i) * (d.z_r - d.z_i) + 4.0 * d.z_r * d.z_i);
		if (dd == 0.0)
			dd = 0.000001;
		d.tmp = d.c_r;
		d.c_r = (2.0 / 3.0) * d.c_r + (d.z_r - d.z_i) / dd;
		d.c_i = (2.0 / 3.0) * d.c_i - 2.0 * d.tmp * d.c_i / dd;
		ret.i++;
	}
	ret.color = get_color_indicator(d.c_r, d.c_i, ret.i);
	ret.z = clamp_to_pct4(d.c_r, -5., 1.5);
	return (ret);
}
