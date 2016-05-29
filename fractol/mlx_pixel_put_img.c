/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 20:13:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:28:39 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_pixel_put_img(t_env *w, int x, int y, int rgb)
{
	unsigned int color;

	color = mlx_get_color_value(w->e->mlx, rgb);
	((unsigned int*)w->img_addr)[y * WIN_W + x] = color;
	return (0);
}
