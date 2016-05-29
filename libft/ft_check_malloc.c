/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 21:53:42 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 21:54:49 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_check_malloc(void *assertion)
{
	if (!assertion)
	{
		ft_printf_fd(2, "Fatal: Memory allocation error\n");
		exit(2);
	}
	return (assertion);
}
