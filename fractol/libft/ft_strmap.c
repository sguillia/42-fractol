/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:39:40 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:46:21 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s);
	if (!(ret = (char*)malloc((len + 1) * sizeof(*ret))))
		return (NULL);
	while (*s)
		*(ret++) = f(*(s++));
	*ret = '\0';
	return (ret - len);
}
