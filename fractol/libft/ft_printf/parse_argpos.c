/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:58:01 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	[bonus] parse specified argument position
**	Example : %2$d reads the second argument in place of the first one
**	argpos starts from 1
**	There may be other '$' in the options, whence the limit
*/

char	*parse_argpos(char *params, t_options *options, t_list *output)
{
	int		i;
	char	*limit;

	limit = ft_strchr(params, '*');
	i = limit ? limit - params : ft_strlen(params);
	if (!ft_memchr(params, '$', i))
	{
		options->argpos = output->content_size++;
		return (params);
	}
	limit = ft_memrchr(params, '-', (char*)ft_memchr(params, '$', i) - params);
	options->argpos = ft_atoi(limit ? limit + 1 : params);
	if (options->argpos == 0)
	{
		options->stopflag = 1;
		return (ft_strchr(params, '$'));
	}
	output->content_size = options->argpos + 1;
	return (ft_strchr(params, '$') + 1);
}
