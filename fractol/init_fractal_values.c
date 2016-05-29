/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:09 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:04:13 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_values(t_env *w)
{
	w->itermax = INIT_ITERMAX;
	w->fitermax = (float)w->itermax;
	w->offset_x = OFFSETX_SHRINK(-WIN_W / 2);
	w->offset_y = OFFSETY_SHRINK(WIN_H / 2);
	w->zoom_x = 1;
	w->zoom_y = 1;
	w->center_x = WIN_W / 2;
	w->center_y = WIN_H / 2;
	w->show_center = 0;
	w->mouse_x = 0;
	w->mouse_y = 0;
}
