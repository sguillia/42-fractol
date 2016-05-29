/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:31 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/17 20:04:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Image could be set to black with this line :
**		ft_memset(w.img_addr, 0, w.linesize * WIN_H);
**	but as all pixels are redrawn, it isn't required
*/

#ifdef GPU

void	redraw_fractal(t_env w)
{
	draw_gpu_fractal(w);
	if (w.show_center)
		draw_center(w);
	mlx_put_image_to_window(w.e->mlx, w.win, w.img_ptr, 0, 0);
	mlx_do_sync(w.e->mlx);
}

#else

void	redraw_fractal(t_env w)
{
	draw_fractal(w);
	if (w.show_center)
		draw_center(w);
	mlx_put_image_to_window(w.e->mlx, w.win, w.img_ptr, 0, 0);
	mlx_do_sync(w.e->mlx);
}

#endif
