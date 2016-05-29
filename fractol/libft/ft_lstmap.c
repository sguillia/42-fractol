/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 20:20:19 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/13 17:25:01 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;

	if (!lst)
		return (NULL);
	if (!(newlst = f(lst)))
		return (NULL);
	if (lst->next)
		newlst->next = ft_lstmap(lst->next, f);
	return (newlst);
}
