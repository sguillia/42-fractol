/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aliases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:14:41 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_aliases(t_options *options)
{
	if (ft_strchr("CDOSU", options->specifier))
	{
		options->lmod = LMOD_L;
		options->specifier = ft_tolower(options->specifier);
	}
	if (ft_strchr("XPB", options->specifier))
	{
		options->flags |= FLAG_UPPERCASE;
		options->specifier = ft_tolower(options->specifier);
	}
}
