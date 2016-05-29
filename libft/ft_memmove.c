/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 00:14:16 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:39:34 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == src || n == 0)
		;
	else if (dest < src)
	{
		i = -1;
		while (++i < n)
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	}
	else
	{
		while (n--)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	}
	return (dest);
}
