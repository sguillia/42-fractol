/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:42:46 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Same as itoa_base but with uintmax_t (unsigned)
*/

char	*ft_uintmaxtoa_base(uintmax_t val, uintmax_t base)
{
	char	buf[65];
	int		i;
	char	*ret;

	if (base < 2 || base > 16)
		return (0);
	if (val == 0)
		return (ft_strdup("0"));
	buf[64] = '\0';
	i = 63;
	while (val && i)
	{
		buf[i] = "0123456789ABCDEF"[val % base];
		val /= base;
		i--;
	}
	ret = ft_strdup(&buf[i + 1]);
	return (ret);
}
