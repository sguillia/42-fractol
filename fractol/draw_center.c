/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:31 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/07 18:56:42 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_center(t_env w)
{
	int x;
	int y;
	int d;

	d = 5;
	y = w.center_y - d;
	while (y <= w.center_y + d)
	{
		x = w.center_x - d;
		while (x <= w.center_x + d)
		{
			mlx_pixel_put_img(&w, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}
