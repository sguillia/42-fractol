/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:59:04 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:59:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_bits(unsigned int c, int rstart, int len)
{
	c >>= (rstart - len);
	c &= ft_expo(2, len) - 1;
	return (c);
}
