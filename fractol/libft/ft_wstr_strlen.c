/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:58:47 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:59:33 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstr_strlen(unsigned int *wstr)
{
	int len;

	len = 0;
	while (*wstr)
	{
		len += ft_wchar_numbytes(*wstr);
		wstr++;
	}
	return (len);
}
