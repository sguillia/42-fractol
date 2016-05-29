/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 00:03:40 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/03 20:31:14 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t s1len;
	size_t s2len;
	size_t min;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	min = (s1len < s2len) ? s1len : s2len;
	min++;
	min = (min < n) ? min : n;
	if (s1len == s2len)
		return (ft_memcmp(s1, s2, min));
	return (ft_memcmp(s1, s2, min));
}
