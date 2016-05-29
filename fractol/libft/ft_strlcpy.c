/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 23:39:24 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:45:54 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t diff;

	diff = size;
	while (src[0] && --size)
		(dst++)[0] = (src++)[0];
	dst[0] = '\0';
	return (diff - size);
}
