/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:00:30 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:29:22 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_preset	*preset2(void)
{
	static t_preset	ret;

	ret.fractalft = mandelbrot;
	ret.fractalft_num = 1;
	ret.colorft = color2;
	ret.itermax = 78;
	ret.colorft_num = 2;
	ret.ofsx = 1.028902026991631580;
	ret.ofsy = 1.484669702590848184;
	ret.zoomx = 16674.540931185081717558;
	ret.zoomy = 16674.540931185081717558;
	ret.ctrx = 450;
	ret.ctry = 400;
	return (&ret);
}
