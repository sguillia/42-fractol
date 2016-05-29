/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:01:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a string of [num] characters, filled with [c]
*/

char	*get_n_chars(int num, char c)
{
	char *ret;

	if (num <= 0)
	{
		if ((ret = ft_strdup("")))
			return (ret);
		else
			exit(myerror("Null malloc"));
	}
	if (!(ret = (char*)malloc((num + 1) * sizeof(*ret))))
		exit(myerror("Null malloc"));
	ret[num] = '\0';
	while (--num >= 0)
		ret[num] = c;
	return (ret);
}
