/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyreleased.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:22 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/06 22:54:23 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyreleased(int keycode, t_env *w)
{
	if (keycode < KEYCODE_MAX)
		w->keys[keycode] = 0;
	return (0);
}
