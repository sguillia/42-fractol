/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizettoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:01:42 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Same as itoa_base but with size_t
*/

char	*ft_sizettoa_base(size_t val, size_t base)
{
	char	buf[34];
	size_t	i;
	char	*ret;

	if (base < 2 || base > 16)
		return (0);
	if (val == 0)
		return (ft_strdup("0"));
	buf[33] = '\0';
	i = 32;
	while (val && i)
	{
		buf[i] = "0123456789ABCDEF"[val % base];
		val /= base;
		i--;
	}
	ret = ft_strdup(&buf[i + 1]);
	return (ret);
}
