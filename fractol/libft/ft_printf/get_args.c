/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:53:57 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	get_next_arglink
**	Return the next va_arg argument passed into a chain link
*/

static t_list	*get_next_arglink(va_list *ap)
{
	t_list *ret;

	if (!(ret = ft_lstnew(NULL, 0)))
		return (NULL);
	ret->content = va_arg(*ap, void*);
	return (ret);
}

/*
**	Returns the [argnum]th argument of the list
**	If argument hasn't already been read by get_next_arglink, then
**		it will create a new link with the next argument,
**		until argnum is reached
*/

void			*get_arg(int argnum, t_list *lst, va_list *ap)
{
	if (argnum <= 0)
		return (lst->content);
	if (!lst->next)
		if (!(lst->next = get_next_arglink(ap)))
			exit(myerror("Malloc error"));
	return (get_arg(argnum - 1, lst->next, ap));
}
