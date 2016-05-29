/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:59:17 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:32:26 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Makes a virtual field filled with spaces, and puts str to the left
*/

char	*adjust_left(char *str, int field_width)
{
	char	*blank;
	char	*ret;

	blank = get_n_chars(field_width - ft_strlen(str), ' ');
	if (!(ret = ft_strjoin(str, blank)))
		exit(myerror("Null malloc"));
	free(str);
	free(blank);
	return (ret);
}
