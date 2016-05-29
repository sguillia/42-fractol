/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:00:30 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:35:31 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_preset	*preset4(void)
{
	static t_preset	ret;

	ret.fractalft = newton;
	ret.colorft = color6;
	ret.itermax = 8;
	ret.colorft_num = 6;
	ret.fractalft_num = 3;
	ret.ofsx = 2.108390722798901162;
	ret.ofsy = 1.199999999999999956;
	ret.zoomx = 4.177248169415655354;
	ret.zoomy = 4.177248169415655354;
	ret.ctrx = 450;
	ret.ctry = 400;
	return (&ret);
}
