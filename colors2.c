/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:26:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:36:17 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROM_KERNEL
# include "fractol.h"
#endif

static int	palette(float pct1)
{
	static int	p1[] = {50, 0, 128};
	static int	p2[] = {255, 14, 117};
	static int	p3[] = {255, 255, 0};
	float		pct2;

	if (pct1 <= 0.5)
	{
		pct1 = pct1 * 2.;
		pct2 = 1.0 - pct1;
		return (RGB(
					(int)(pct2 * p1[0]) + (int)(pct1 * p2[0]),
					(int)(pct2 * p1[1]) + (int)(pct1 * p2[1]),
					(int)(pct2 * p1[2]) + (int)(pct1 * p2[2])));
	}
	else
	{
		pct2 = 1.0 - pct1;
		return (RGB(
					(int)(pct2 * p2[0]) + (int)(pct1 * p3[0]),
					(int)(pct2 * p2[1]) + (int)(pct1 * p3[1]),
					(int)(pct2 * p2[2]) + (int)(pct1 * p3[2])));
	}
}

int			color6(t_iter ret, int itermax)
{
	double pct;

	(void)itermax;
	pct = ret.z / 4.;
	pct = 1 - pct;
	return (palette((float)pct));
}
