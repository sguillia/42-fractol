/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:28:58 by sguillia          #+#    #+#             */
/*   Updated: 2015/11/29 20:25:46 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *str;

	if (!(str = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	return (ft_strcpy(str, s));
}
