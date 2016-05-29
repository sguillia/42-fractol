/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:40:06 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds a string to the buffer, so that nothing is printed if an error occurs
**	Code 0 = Do not free content
**	Code 1 = Free content
*/

void	ft_printf_buffer_add(t_list *output, void *content, size_t code)
{
	t_list *lst;

	if (!(lst = ft_lstnew(NULL, 0)))
		exit(myerror("Null malloc"));
	lst->content = content;
	lst->content_size = code;
	ft_lstaddend(output, lst);
}
