/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:20:26 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/24 11:41:53 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ret;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(ret = (char*)malloc((s1len + s2len + 1) * sizeof(*ret))))
		return (NULL);
	ret[0] = '\0';
	ft_strncpy(ret, s1, s1len);
	ft_strncpy(ret + s1len, s2, s2len + 1);
	return (ret);
}
