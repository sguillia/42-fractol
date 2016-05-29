/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:43:28 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:32:33 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Makes a virtual field filled with spaces, and puts str to the right
*/

char	*adjust_right(char *str, int field_width)
{
	char	*blank;
	char	*ret;

	blank = get_n_chars(field_width - ft_strlen(str), ' ');
	if (!(ret = ft_strjoin(blank, str)))
		exit(myerror("Null malloc"));
	free(blank);
	free(str);
	return (ret);
}
