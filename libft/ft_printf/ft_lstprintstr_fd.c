/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:37:39 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	- Prints all the string contents of a list
**	- Frees all links, and contents if content_size is equal to 1
**	- Returns the number of written bytes (except null chars)
*/

int		ft_lstprintstr_fd(t_list *lst, int fd)
{
	t_list	*next;
	size_t	len;

	if (!lst)
		return (0);
	ft_putstr_fd((char*)lst->content, fd);
	len = ft_strlen((char*)lst->content);
	if (lst->content_size == 1)
		free(lst->content);
	next = lst->next;
	free(lst);
	return (len + ft_lstprintstr_fd(next, fd));
}
