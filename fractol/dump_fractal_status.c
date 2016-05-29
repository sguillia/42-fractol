/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_fractal_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 20:43:08 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 20:17:58 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef PRECISION

void	dump_fractal_status(t_env w)
{
	ft_printf("Max iter %cyan;%3d%;, ", w.itermax);
	ft_printf("Ctr x  %cyan;%3d%;, ", w.center_x);
	ft_printf("Ctr y  %cyan;%3d%;\n", w.center_y);
	dprintf(1, "Ofs x  %.18f, ", w.offset_x);
	dprintf(1, "Ofs y  %.18f\n", w.offset_y);
	dprintf(1, "Zoom x  %.18f, ", w.zoom_x);
	dprintf(1, "Zoom y  %.18f\n", w.zoom_y);
}

#else

void	dump_fractal_status(t_env w)
{
	ft_printf("Max iter %cyan;%3d%;, ", w.itermax);
	ft_printf("Ofs x  %cyan;%3d%;, ", OFFSETX_DEPLOY(w.offset_x));
	ft_printf("Ofs y  %cyan;%3d%;, ", OFFSETY_DEPLOY(w.offset_y));
	ft_printf("Zoom x  %cyan;%3d%;, ", (int)(w.zoom_x * 10));
	ft_printf("Zoom y  %cyan;%3d%;, ", (int)(w.zoom_y * 10));
	ft_printf("Ctr x  %cyan;%3d%;, ", w.center_x);
	ft_printf("Ctr y  %cyan;%3d%;\n", w.center_y);
}

#endif
