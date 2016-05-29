/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:39:40 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:46:30 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	if (!(ret = (char*)malloc((len + 1) * sizeof(*ret))))
		return (NULL);
	while (*s)
		*(ret++) = f(i++, *(s++));
	*ret = '\0';
	return (ret - len);
}
