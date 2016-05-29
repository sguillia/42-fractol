/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 22:20:53 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Same as ft_strjoin but with 3 strings
*/

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	size_t	s1len;
	size_t	s2len;
	size_t	s3len;
	char	*ret;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3len = ft_strlen(s3);
	if (!(ret = (char*)malloc((s1len + s2len + s3len + 1) * sizeof(*ret))))
		return (NULL);
	ret[0] = '\0';
	ft_strcpy(ret, s1);
	ft_strcpy(ret + s1len, s2);
	ft_strcpy(ret + s1len + s2len, s3);
	return (ret);
}
