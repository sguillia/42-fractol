/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:03 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 21:39:15 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_envs(t_mlx *e, t_env *wins, int ac)
{
	int		i;

	i = 0;
	while (++i < ac)
		init_fractal(e, &wins[i - 1]);
	if (i == 1 && DEFAULT)
		init_fractal(e, &wins[0]);
}
