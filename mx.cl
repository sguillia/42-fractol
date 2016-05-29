#include "size.h"
#include "typedefs.cl"
#include "colors.c"
#include "colors2.cl"

static double   clamp_to_pct4(double input, double min, double max)
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

static int      get_color_indicator(double dcr, double dci, int i)
{
	if (dcr > 0.0)
		return (i % 64);
	else if ((dcr < -0.3) && (dci > 0.0))
		return ((i % 64) + 64);
	else
		return ((i % 64) + 128);
}

__kernel void iterate(
		__global char *output,
		double	d_zoom_x,
		double	d_zoom_y,
		int		center_x,
		int		center_y,
		double	offset_x,
		double	offset_y,
		int		mouse_x,
		int		mouse_y,
		char	colorft_num,
		int		itermax,
		char	fractalft_num)
{
	int		id;
	int		x;
	int		y;
	int		color;
	t_iter	ret;
	t_calc	d;
	double  dd;

	id = get_global_id(0);
	if (id < 0 || id >= WIN_W * WIN_H)
		return ;

	x = id % WIN_W;
	y = id / WIN_W;

	if (fractalft_num == 1)
	{
		d.zoom_x = d_zoom_x;
		d.zoom_y = d_zoom_y;
		d.c_r = ((double)x - center_x) / d.zoom_x + X1 + offset_x;
		d.c_i = ((double)center_y - y) / d.zoom_y + Y1 + (offset_y);
		d.z_r = 0;
		d.z_i = 0;
		ret.i = 0;
		while (d.z_r * d.z_r + d.z_i * d.z_i < 4.0 && ret.i < itermax)
		{
			d.tmp = d.z_r;
			d.z_r = d.z_r * d.z_r - d.z_i * d.z_i + d.c_r;
			d.z_i = 2.0 * d.z_i * d.tmp + d.c_i;
			ret.i++;
		}
		ret.z = d.z_r * d.z_r + d.z_i * d.z_i;
		if (ret.z > 4.0)
			ret.z = 4.0;
		if (ret.z < 0.0)
			ret.z = 0.0;
		ret.color = 0;
	}

	else if (fractalft_num == 2)
	{
		d.zoom_x = d_zoom_x;
		d.zoom_y = d_zoom_y;
		d.z_r = ((double)x - center_x) / d.zoom_x + X1 + offset_x;
		d.z_i = ((double)center_y - y) / d.zoom_y + Y1 + (offset_y);
		d.c_r = (double)mouse_x / 1000 - 1;
		d.c_i = (double)mouse_y / 400 - 1;
		ret.i = 0;
		while (d.z_r * d.z_r + d.z_i * d.z_i < 4 && ret.i < itermax)
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
	}

	else
	{
		d.zoom_x = d_zoom_x;
		d.zoom_y = d_zoom_y;
		d.c_r = ((double)x - center_x) / d.zoom_x + X1 + offset_x;
		d.c_i = ((double)center_y - y) / d.zoom_y + Y1 + (offset_y);
		ret.i = 0;
		while (ret.i < itermax)
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
	}

	color = 0;
	switch(colorft_num)
	{
		case 1:
			color = color1(ret, itermax);
			break ;
		case 2:
			color = color2(ret, itermax);
			break ;
		case 3:
			color = color3(ret, itermax);
			break ;
		case 4:
			color = color4(ret, itermax);
			break ;
		case 5:
			color = color5(ret, itermax);
			break ;
		case 6:
			color = color6(ret, itermax);
			break ;
	}
	((unsigned int*)output)[id] = color;
}
