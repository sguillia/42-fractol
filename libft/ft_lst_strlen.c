/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 21:37:44 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 21:38:57 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_strlen(t_list *lst)
{
	if (lst)
		return (ft_strlen(lst->content) + ft_lst_strlen(lst->next));
	else
		return (0);
}
