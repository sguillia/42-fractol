/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:03:24 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	flag_zero_d adds zero's ('0') between the possible symbol and the
**		digit string
*/

static char	*get_begin(char c)
{
	char	*begin;

	if (c == '+' || c == ' ' || c == '-')
	{
		if (!(begin = ft_strnew(1)))
			exit(myerror("Null malloc"));
		*begin = c;
	}
	else
	{
		if (!(begin = ft_strnew(0)))
			exit(myerror("Null malloc"));
	}
	return (begin);
}

char		*flag_zero_d(char *str, int field_width)
{
	char	*ret;
	char	*begin;
	char	*blank;

	begin = get_begin(*str);
	blank = get_n_chars(field_width - ft_strlen(str), '0');
	ret = ft_strjoin3(begin,
				blank,
				str + (*begin ? 1 : 0));
	free(begin);
	free(blank);
	free(str);
	if (!ret)
		exit(myerror("Null malloc"));
	return (ret);
}
