/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:13:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles precision for binary conversion
*/

void	handle_precision_b(t_options *options, t_list *output, char *str)
{
	int		len;
	char	*ret;
	char	*zeros;

	len = ft_strlen(str);
	if (options->precision == 0 && *str == '0')
	{
		if (!(ret = ft_strdup("")))
			exit(myerror("Null malloc"));
		free(str);
		handle_converted_b(options, output, ret);
		return ;
	}
	if (options->precision == -1 || len >= options->precision)
	{
		handle_converted_b(options, output, str);
		return ;
	}
	zeros = get_n_chars(options->precision - len, '0');
	ret = ft_strjoin(zeros, str);
	if (!ret)
		exit(myerror("Null malloc"));
	free(zeros);
	free(str);
	handle_converted_b(options, output, ret);
}
