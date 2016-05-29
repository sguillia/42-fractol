/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_refresh_fractal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:34 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/15 18:44:01 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	try_refresh_fractal(t_env *w)
{
	int		exec;

	exec = consider_inputs(w);
	if (w->mouse_changed == 1 || exec || w->itermax != (int)w->fitermax)
	{
		if (w->mouse_changed != -1)
			w->mouse_changed = 0;
		w->itermax = (int)w->fitermax;
		dump_fractal_status(*w);
		redraw_fractal(*w);
	}
}
