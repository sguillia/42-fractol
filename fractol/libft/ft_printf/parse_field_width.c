/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:48:40 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Parses minimum field width
**	May be specified in argument
**	Examples :
**		%10d
**		%*d
**		%*2$d
*/

static char	*parse_asterisk(char *params, t_options *options, t_list *output)
{
	char	*ret;
	int		argnum;
	int		max;
	int		mfwpos;

	params++;
	ret = ft_strchr(params, '.');
	max = ret ? ret - params : ft_strlen(params);
	ret = ft_memchr(params, '$', max);
	if (ret && !(argnum = ft_atoi(params)))
		return (ret + 1);
	else if (ret)
		mfwpos = argnum;
	else
		mfwpos = options->argpos++;
	options->field_width = (int)get_arg(mfwpos,
			output->content,
			((t_list*)output->content)->content);
	output->content_size = options->argpos + 1;
	return (ret ? ret + 1 : params);
}

char		*parse_field_width(char *params, t_options *options, t_list *output)
{
	if (options->stopflag)
		return (params);
	if (*params == '*')
		return (parse_asterisk(params, options, output));
	else
	{
		options->field_width = ft_atoi(params);
		while (ft_isdigit(*params) || *params == '-')
			params++;
		return (params);
	}
}
