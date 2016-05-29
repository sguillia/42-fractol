/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:00:30 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:14:59 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_preset	*preset3(void)
{
	static t_preset	ret;

	ret.fractalft = mandelbrot;
	ret.colorft = color4;
	ret.itermax = 169;
	ret.colorft_num = 4;
	ret.fractalft_num = 1;
	ret.ofsx = 1.363993138603982969;
	ret.ofsy = 1.481525173711602417;
	ret.zoomx = 112177.962221639885683544;
	ret.zoomy = 112177.962221639885683544;
	ret.ctrx = 450;
	ret.ctry = 400;
	return (&ret);
}
