/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:00:30 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 23:45:06 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_preset	*preset5(void)
{
	static t_preset	ret;

	ret.fractalft = julia;
	ret.colorft = color6;
	ret.itermax = 20;
	ret.colorft_num = 6;
	ret.fractalft_num = 2;
	ret.ofsx = 1.350000000000000089;
	ret.ofsy = 1.199999999999999956;
	ret.zoomx = 1.0;
	ret.zoomy = 1.0;
	ret.ctrx = 450;
	ret.ctry = 400;
	return (&ret);
}
