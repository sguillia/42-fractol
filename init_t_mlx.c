/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/17 14:16:22 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef GPU

void	init_t_mlx(t_mlx *e)
{
	opencl_init(e);
	if (!(e->mlx = mlx_init()))
		exit_str("Failed to init mlx");
	mlx_do_key_autorepeatoff(e->mlx);
}

#else

void	init_t_mlx(t_mlx *e)
{
	if (!(e->mlx = mlx_init()))
		exit_str("Failed to init mlx");
	mlx_do_key_autorepeatoff(e->mlx);
}

#endif
