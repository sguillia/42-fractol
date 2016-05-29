/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 18:42:01 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:36:44 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- && *(unsigned char*)(s1++) == *(unsigned char*)(s2++))
		;
	return (n + 1 ?
		(*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1)) : 0);
}
