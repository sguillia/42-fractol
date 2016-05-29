/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:13:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles precision for d specifier
*/

static void	check_malloc(char *ret)
{
	if (!ret)
		exit(myerror("Null malloc"));
}

void		handle_precision_d(t_options *options, t_list *output, char *str)
{
	int		len;
	char	*ret;
	char	*zeros;

	len = ft_strlen(str) - ((*str == '-') ? 1 : 0);
	if (options->precision == 0 && *str == '0')
	{
		check_malloc(ret = ft_strdup(""));
		free(str);
		handle_converted_d(options, output, ret);
	}
	else if (options->precision == -1 || len >= options->precision)
		handle_converted_d(options, output, str);
	else
	{
		zeros = get_n_chars(options->precision - len, '0');
		if (*str == '-')
			ret = ft_strjoin3("-", zeros, str + 1);
		else
			ret = ft_strjoin(zeros, str);
		check_malloc(ret);
		free(zeros);
		free(str);
		handle_converted_d(options, output, ret);
	}
}
