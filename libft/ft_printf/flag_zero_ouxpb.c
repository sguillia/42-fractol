/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_ouxpb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:03:24 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	flag_zero_ouxpb handles specifiers o u x p and b
**	It adds zero's ('0') between the possible prefix (0x 0b 0X 0B 0) and
**		the converted string
*/

static char	*get_begin(char c1, char c2)
{
	char	*begin;

	if (c1 == '0' && (c2 == 'x' || c2 == 'X' || c2 == 'b' || c2 == 'B'))
	{
		if (!(begin = ft_strnew(2)))
			exit(myerror("Null malloc"));
		*begin = c1;
		*(begin + 1) = c2;
	}
	else
	{
		if (!(begin = ft_strnew(0)))
			exit(myerror("Null malloc"));
	}
	return (begin);
}

char		*flag_zero_ouxpb(char *str, int field_width)
{
	char	*ret;
	char	*begin;
	char	*blank;

	begin = get_begin(*str, *(str + 1));
	blank = get_n_chars(field_width - ft_strlen(str), '0');
	ret = ft_strjoin3(begin,
				blank,
				str + (*begin ? 2 : 0));
	free(begin);
	free(blank);
	free(str);
	if (!ret)
		exit(myerror("Null malloc"));
	return (ret);
}
