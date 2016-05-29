/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:17:57 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:29:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *w)
{
	if (button == 1 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		w->show_center = 1;
		set_zoom_center(w, x, y);
		redraw_fractal(*w);
	}
	if (button == 4 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		w->show_center = 0;
		set_zoom_center(w, x, y);
		w->zoom_x *= ZOOM_DELTA_MUL;
		w->zoom_y *= ZOOM_DELTA_MUL;
		redraw_fractal(*w);
		set_zoom_center(w, WIN_W / 2, WIN_H / 2);
	}
	if (button == 5 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		w->show_center = 0;
		set_zoom_center(w, x, y);
		w->zoom_x /= ZOOM_DELTA_MUL;
		w->zoom_y /= ZOOM_DELTA_MUL;
		redraw_fractal(*w);
		set_zoom_center(w, WIN_W / 2, WIN_H / 2);
	}
	return (0);
}
