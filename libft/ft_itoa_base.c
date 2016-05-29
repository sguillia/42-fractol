/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 00:16:08 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/06 22:03:41 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** WARNINGS
** - Always check if this function returns NULL or not
** - The algo may return a string equivalent to more than INT_MAX when
**  i = INT_MIN and base != 10
** INFOS
** - The return value does never begin by 0, they are skipped
** - If base != 10 then the number is considered unsigned
**		ft_itoa_base(32, 2)  ==  ft_itoa_base(-32, 2)
*/

char	*ft_itoa_base(int val, int base)
{
	char	buf[34];
	int		i;
	int		is_neg;
	char	*ret;

	if (base < 2 || base > 16)
		return (0);
	if (val == 0)
		return (ft_strdup("0"));
	buf[33] = '\0';
	i = 32;
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
