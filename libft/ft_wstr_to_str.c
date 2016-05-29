/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:58:53 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:58:57 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstr_to_str(unsigned int *wstr)
{
	char	*str;
	int		index;

	if (!(str = (char*)malloc((ft_wstr_strlen(wstr) + 1) * sizeof(*str))))
		return (NULL);
	index = 0;
	while (*wstr)
	{
		index += ft_wchar_to_str(&str[index], *wstr);
		wstr++;
	}
	return (str);
}
