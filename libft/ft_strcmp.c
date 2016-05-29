/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 00:03:40 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/03 20:29:18 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t s1len;
	size_t s2len;
	size_t min;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	min = (s1len < s2len) ? s1len : s2len;
	return (ft_memcmp(s1, s2, min + 1));
}
