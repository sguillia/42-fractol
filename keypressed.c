/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:14 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 23:05:58 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keypressed(int keycode, t_env *w)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_SPACE)
		w->mouse_changed = (w->mouse_changed == -1) ? 1 : -1;
	if (keycode < KEYCODE_MAX)
		w->keys[keycode] = 1;
	return (0);
}
