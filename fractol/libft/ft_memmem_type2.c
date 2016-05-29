/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:21:42 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:39:13 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** CAUTION
** The implementation of this function differs between versions
** Type 1 = at line 28, return NULL
** Type 2 = at line 28, return (void*)haystack
*/

void	*ft_memmem_type2(const void *haystack, size_t haystacklen,
		const void *needle, size_t needlelen)
{
	if (needlelen > haystacklen)
		return (NULL);
	if (needlelen == 0)
		return ((void*)haystack);
	while (haystacklen-- >= needlelen)
	{
		if (ft_memcmp(haystack, needle, needlelen) == 0)
			return ((void*)haystack);
		haystack++;
	}
	return (NULL);
}
