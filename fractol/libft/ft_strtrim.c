/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:07:59 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:48:51 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	while (*s && ft_is42space(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	while (ft_is42space(*(s + len - 1)))
		len--;
	if (!(str = (char*)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
