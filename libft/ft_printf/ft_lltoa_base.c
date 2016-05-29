/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 00:16:08 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Same as itoa_base but with long long
*/

char	*ft_lltoa_base(long long val, long long base)
{
	char	buf[65];
	int		i;
	int		is_neg;
	char	*ret;

	if (base < 2 || base > 16)
		return (0);
	if (val == 0)
		return (ft_strdup("0"));
	buf[64] = '\0';
	i = 63;
	is_neg = val < 0;
	while (val && i)
	{
		buf[i] = "0123456789ABCDEF"[(val % base) * (is_neg ? -1 : 1)];
		val /= base;
		i--;
	}
	buf[i] = '-';
	ret = ft_strdup(&buf[i + ((is_neg && base == 10) ? 0 : 1)]);
	return (ret);
}
