/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_casters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 14:38:39 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Caster = length modifier
*/

char	*parse_casters(char *params, t_options *options)
{
	if (options->stopflag)
		return (params);
	if (!ft_strcmp(params, "hh"))
		options->lmod = LMOD_HH;
	else if (!ft_strcmp(params, "h"))
		options->lmod = LMOD_H;
	else if (!ft_strcmp(params, "ll"))
		options->lmod = LMOD_LL;
	else if (!ft_strcmp(params, "l"))
		options->lmod = LMOD_L;
	else if (!ft_strcmp(params, "j"))
		options->lmod = LMOD_J;
	else if (!ft_strcmp(params, "z"))
		options->lmod = LMOD_Z;
	return (ft_strchr(params, '\0'));
}
