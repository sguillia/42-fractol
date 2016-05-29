/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consider_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:53:36 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 23:45:28 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	consider_inputs5(t_env *w)
{
	int		exec;
	char	*keys;

	keys = w->keys;
	exec = 0;
	if (keys[KEY_1] && (exec = 1))
		load_preset(w, preset1());
	if (keys[KEY_2] && (exec = 1))
		load_preset(w, preset2());
	if (keys[KEY_3] && (exec = 1))
		load_preset(w, preset3());
	if (keys[KEY_4] && (exec = 1))
		load_preset(w, preset4());
	if (keys[KEY_5] && (exec = 1))
		load_preset(w, preset5());
	return (exec);
}

static int	consider_inputs4(t_env *w)
{
	int		exec;
	char	*keys;

	keys = w->keys;
	exec = 0;
	if (keys[KEY_Z] && (exec = 1))
		w->colorft_num = 1;
	if (keys[KEY_X] && (exec = 1))
		w->colorft_num = 2;
	if (keys[KEY_C] && (exec = 1))
		w->colorft_num = 3;
	if (keys[KEY_V] && (exec = 1))
		w->colorft_num = 4;
	if (keys[KEY_B] && (exec = 1))
		w->colorft_num = 5;
	if (keys[KEY_N] && (exec = 1))
		w->colorft_num = 6;
	return (exec + consider_inputs5(w));
}

static int	consider_inputs3(t_env *w)
{
	int		exec;
	char	*keys;

	keys = w->keys;
	exec = 0;
	if (keys[KEY_Z] && (exec = 1))
		w->colorft = color1;
	if (keys[KEY_X] && (exec = 1))
		w->colorft = color2;
	if (keys[KEY_C] && (exec = 1))
		w->colorft = color3;
	if (keys[KEY_V] && (exec = 1))
		w->colorft = color4;
	if (keys[KEY_B] && (exec = 1))
		w->colorft = color5;
	if (keys[KEY_N] && (exec = 1))
		w->colorft = color6;
	return (exec + consider_inputs4(w));
}

/*
**	Iterations, reset and zoom + -
*/

static int	consider_inputs2(t_env *w)
{
	int		exec;
	char	*keys;

	keys = w->keys;
	exec = 0;
	if (keys[KEY_I])
		w->fitermax += ITER_DELTA;
	if (keys[KEY_K] && w->fitermax >= ITERMAX_MIN + ITER_DELTA)
		w->fitermax -= ITER_DELTA;
	if (keys[KEY_R] && (exec = 1))
		init_fractal_values(w);
	if ((keys[KEY_F17] || keys[KEY_F19]) && (exec = 1))
		w->zoom_x -= ZOOM_DELTA_ADD;
	if ((keys[KEY_F18] || keys[KEY_F19]) && (exec = 1))
		w->zoom_y -= ZOOM_DELTA_ADD;
	if ((keys[KEY_PAD_EQUAL] || keys[KEY_PAD_STAR]) && (exec = 1))
		w->zoom_x += ZOOM_DELTA_ADD;
	if ((keys[KEY_PAD_SLASH] || keys[KEY_PAD_STAR]) && (exec = 1))
		w->zoom_y += ZOOM_DELTA_ADD;
	return (exec + consider_inputs3(w));
}

/*
**	Offset and zoom * /
*/

int			consider_inputs(t_env *w)
{
	int		exec;
	char	*keys;

	keys = w->keys;
	exec = 0;
	if (keys[KEY_A] && (exec = 1))
		w->offset_x += OFFSETX_DELTA / w->zoom_x / OFS_ZOOM_PWR;
	if (keys[KEY_D] && (exec = 1))
		w->offset_x -= OFFSETX_DELTA / w->zoom_x / OFS_ZOOM_PWR;
	if (keys[KEY_S] && (exec = 1))
		w->offset_y -= OFFSETY_DELTA / w->zoom_y / OFS_ZOOM_PWR;
	if (keys[KEY_W] && (exec = 1))
		w->offset_y += OFFSETY_DELTA / w->zoom_y / OFS_ZOOM_PWR;
	if ((keys[KEY_PAD_8] || keys[KEY_PAD_MIN]) && (exec = 1))
		w->zoom_x /= ZOOM_DELTA_MUL;
	if ((keys[KEY_PAD_9] || keys[KEY_PAD_MIN]) && (exec = 1))
		w->zoom_y /= ZOOM_DELTA_MUL;
	if ((keys[KEY_PAD_5] || keys[KEY_PAD_PLUS]) && (exec = 1))
		w->zoom_x *= ZOOM_DELTA_MUL;
	if ((keys[KEY_PAD_6] || keys[KEY_PAD_PLUS]) && (exec = 1))
		w->zoom_y *= ZOOM_DELTA_MUL;
	return (exec + consider_inputs2(w));
}
