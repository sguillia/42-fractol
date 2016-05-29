/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zoom_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:06:55 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/07 18:08:02 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_zoom_center(t_env *w, int x, int y)
{
	w->offset_x += OFFSETX_SHRINK((w->center_x - x) / w->zoom_x);
	w->offset_y += OFFSETY_SHRINK((w->center_y - y) / w->zoom_y);
	w->center_x = x;
	w->center_y = y;
}
