/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:01:14 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/17 23:25:30 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	mouse_changed
**	   -1 if paused
**		0  if non-paused but not moved
**		1  if non-paused but moved since last drawing
*/

int		motion_hook(int x, int y, t_env *w)
{
	if (w->fractalft == julia && w->mouse_changed != -1)
	{
		w->mouse_x = x;
		w->mouse_y = y;
		w->mouse_changed = 1;
	}
	return (0);
}
