/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:03:24 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds zero's ('0') before str
*/

char		*flag_zero_s(char *str, int field_width)
{
	char	*ret;
	char	*blank;

	blank = get_n_chars(field_width - ft_strlen(str), '0');
	ret = ft_strjoin(blank, str);
	free(blank);
	free(str);
	if (!ret)
		exit(myerror("Null malloc"));
	return (ret);
}
