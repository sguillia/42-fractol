/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:37:55 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:32:15 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds a prefix to the string
*/

char	*add_prefix(char *prefix, char *str, int free_prefix)
{
	char *ret;

	if (!(ret = ft_strjoin(prefix, str)))
		exit(myerror("Null malloc"));
	if (free_prefix)
		free(prefix);
	free(str);
	return (ret);
}
