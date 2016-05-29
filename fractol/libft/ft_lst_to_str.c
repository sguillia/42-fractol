/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 21:39:45 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 21:43:32 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lst_to_str(t_list *lst)
{
	char	*ret;
	char	*ini_ret;
	size_t	len;

	len = ft_lst_strlen(lst);
	if (!(ret = (char*)malloc((len + 1) * sizeof(*ret))))
		return (NULL);
	ini_ret = ret;
	*ret = '\0';
	while (lst)
	{
		ft_strcpy(ret, (char*)lst->content);
		ret += ft_strlen((char*)lst->content);
		lst = lst->next;
	}
	return (ini_ret);
}
