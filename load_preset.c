/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_preset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:02:24 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:20:41 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	load_preset(t_env *w, t_preset *preset)
{
	w->fractalft = preset->fractalft;
	w->fractalft_num = preset->fractalft_num;
	w->colorft = preset->colorft;
	w->colorft_num = preset->colorft_num;
	w->itermax = preset->itermax;
	w->fitermax = (float)preset->itermax;
	w->offset_x = preset->ofsx;
	w->offset_y = preset->ofsy;
	w->zoom_x = (double)preset->zoomx;
	w->zoom_y = (double)preset->zoomy;
	w->center_x = preset->ctrx;
	w->center_y = preset->ctry;
}
