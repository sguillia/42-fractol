/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:00:30 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:14:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_preset	*preset1(void)
{
	static t_preset	ret;

	ret.fractalft = mandelbrot;
	ret.fractalft_num = 1;
	ret.colorft = color4;
	ret.itermax = 72;
	ret.colorft_num = 4;
	ret.ofsx = OFFSETX_SHRINK(-112);
	ret.ofsy = OFFSETY_SHRINK(399);
	ret.zoomx = 25.5;
	ret.zoomy = 25.5;
	ret.ctrx = 450;
	ret.ctry = 400;
	return (&ret);
}
