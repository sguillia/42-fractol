/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nonmodulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:57:01 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/04 22:06:40 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles non=modulo characters in format, until null byte or '%'
*/

const char	*handle_nonmodulo(const char *format, t_list *output)
{
	char	*modulo_pos;
	char	*stock;
	t_list	*lst;

	modulo_pos = ft_strchr(format, '%');
	if (modulo_pos == format)
		return (format);
	if (modulo_pos)
		stock = ft_strsub(format, 0, modulo_pos - format);
	else
		stock = ft_strdup(format);
	if (!(lst = ft_lstnew(NULL, 0)))
		exit(myerror("Null malloc"));
	lst->content = (void*)stock;
	lst->content_size = 1;
	ft_lstaddend(output, lst);
	return (format + ft_strlen(stock));
}
