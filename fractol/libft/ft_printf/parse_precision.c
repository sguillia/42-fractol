/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:48:52 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Parses precision
**	May be specified in argument
**	Examples :
**		%.10d
**		%.*d
**		%.*2$d
*/

static char	*parse_asterisk(char *params, t_options *options, t_list *output)
{
	char	*ret;
	int		argnum;
	int		prec_pos;

	params++;
	ret = ft_strchr(params, '$');
	if (ret && !(argnum = ft_atoi(params)))
		return (ret + 1);
	else if (ret)
		prec_pos = argnum;
	else
		prec_pos = options->argpos++;
	options->precision = (int)get_arg(prec_pos,
			output->content,
			((t_list*)output->content)->content);
	output->content_size = options->argpos + 1;
	return (ret ? ret + 1 : params);
}

char		*parse_precision(char *params, t_options *options, t_list *output)
{
	if (options->stopflag)
		return (params);
	if (*params != '.')
		return (params);
	params++;
	if (*params == '*')
		return (parse_asterisk(params, options, output));
	else if (!ft_isdigit(*params))
		options->precision = 0;
	else
	{
		options->precision = ft_atoi(params);
		while (ft_isdigit(*params))
			params++;
	}
	return (params);
}
