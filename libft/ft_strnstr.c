/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 13:13:48 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/25 18:13:58 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t big_len;

	big_len = ft_strlen(big);
	if (len > big_len)
		len = big_len;
	return ((char*)ft_memmem_type2(big, len, little, ft_strlen(little)));
}
