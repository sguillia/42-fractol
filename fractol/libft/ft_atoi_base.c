/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 01:49:21 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 19:25:13 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexchar_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

/*
** If base < 2 || base > 16 || null str then return 0;
** ABCDEF and abcdef are ok (condition in ft_hexchar_to_int)
** The algo skip spaces (isspace) then stops at the first non-valid
** char, e.g. spaces
** '-' or '+' taken into account only if it is the first char after
** skipping spaces
*/

int			ft_atoi_base(const char *str, int base)
{
	int			total;
	short int	val;
	char		factor;

	if (base < 2 || base > 16)
		return (0);
	while (ft_isspace(str[0]))
		str++;
	factor = (str[0] == '-') ? -1 : 1;
	str += (str[0] == '-' || str[0] == '+') ? 1 : 0;
	total = 0;
	while (str[0])
	{
		val = ft_hexchar_to_int(str[0]);
		if (val >= base || val == -1)
			break ;
		total *= base;
		total += val;
		str++;
	}
	return (total * factor);
}
