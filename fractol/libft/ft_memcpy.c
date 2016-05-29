/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 14:01:20 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:37:56 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	n_cpy;

	n_cpy = n;
	while (n--)
		((unsigned char*)dest++)[0] = ((unsigned char*)src++)[0];
	return (dest - n_cpy);
}
