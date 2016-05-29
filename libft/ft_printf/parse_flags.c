/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:58:18 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	While (char is a flag)
**		Transform (char) to (binary mask)
**	See ft_printf.h flag defines
*/

char	*parse_flags(char *params, t_options *options)
{
	char *flags;
	char c;

	if (options->stopflag)
		return (params);
	flags = "#0- +'";
	while ((c = *params) && ft_strchr(flags, c) && params++)
		options->flags |= 1 << (ft_strchr(flags, c) - flags);
	return (params);
}
