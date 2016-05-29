/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:25:02 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/22 20:26:48 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	s_len;
	size_t	len;

	s_len = ft_strlen(s);
	len = n < s_len ? n : s_len;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
