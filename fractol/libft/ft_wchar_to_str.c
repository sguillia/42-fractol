/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:58:38 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:58:43 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wchar_to_str(char *dest, unsigned int c)
{
	int		size;

	size = ft_wchar_numbytes(c);
	if (size == 1)
		*(dest++) = c;
	else if (size == 2)
	{
		*(dest++) = ft_get_bits(c, 11, 5) | WMASK2;
		*(dest++) = ft_get_bits(c, 6, 6) | WMASK1;
	}
	else if (size == 3)
	{
		*(dest++) = ft_get_bits(c, 16, 4) | WMASK3;
		*(dest++) = ft_get_bits(c, 12, 6) | WMASK1;
		*(dest++) = ft_get_bits(c, 6, 6) | WMASK1;
	}
	else
	{
		*(dest++) = ft_get_bits(c, 21, 3) | WMASK4;
		*(dest++) = ft_get_bits(c, 18, 6) | WMASK1;
		*(dest++) = ft_get_bits(c, 12, 6) | WMASK1;
		*(dest++) = ft_get_bits(c, 6, 6) | WMASK1;
	}
	*dest = '\0';
	return (size);
}
