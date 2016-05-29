/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:25 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/16 21:23:14 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef GPU

int		loop_hook(t_mlx *e)
{
	try_refresh_fractal(e->wins);
	return (0);
}

#else

int		loop_hook(t_mlx *e)
{
	try_refresh_fractal(e->wins);
	if (e->wins[1].win)
		try_refresh_fractal(&e->wins[1]);
	if (e->wins[2].win)
		try_refresh_fractal(&e->wins[2]);
	return (0);
}

#endif
