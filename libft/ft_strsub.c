/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:40:12 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/23 21:55:17 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!(ret = (char*)malloc((len + 1) * sizeof(*ret))))
		return (NULL);
	*ret = '\0';
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
