/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 23:01:22 by sguillia          #+#    #+#             */
/*   Updated: 2015/10/13 23:04:47 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stralloc(char *str, size_t n)
{
	return (n > ft_strlen(str) ? ft_strcpy(ft_strnew(n), str) : NULL);
}
