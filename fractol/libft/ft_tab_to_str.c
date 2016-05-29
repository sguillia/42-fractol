/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:18:51 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 21:54:59 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocate memory and concatenates all strings in tab
**	If separator is not a null byte, the separator char is put between
**		each str
*/

char	*ft_tab_to_str(char **tab, char separator)
{
	char	*str;
	char	*ret;
	size_t	totallen;
	size_t	separatorlen;

	separatorlen = ft_tablen(tab) ? ft_tablen(tab) - 1 : 0;
	totallen = ft_tab_strlen(tab) + (separator ? separatorlen : 0) + 1;
	ret = (char*)malloc(totallen * sizeof(*ret));
	ft_check_malloc(ret);
	str = ret;
	while (*tab)
	{
		ft_strcpy(str, *tab);
		str = ft_strchr(str, '\0');
		if (separator && *(tab + 1))
			*(str++) = separator;
		tab++;
	}
	return (ret);
}
