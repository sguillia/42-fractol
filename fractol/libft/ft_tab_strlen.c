/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:18:00 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 21:36:11 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the sum of all strings strlen
*/

size_t	ft_tab_strlen(char **tab)
{
	size_t ret;

	ret = 0;
	while (*tab)
	{
		ret += ft_strlen(*tab);
		tab++;
	}
	return (ret);
}
