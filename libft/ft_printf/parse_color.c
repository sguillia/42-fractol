/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:40:08 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Parse color
**	Example : "%red; hello %;"
*/

int		parse_color(char *params, t_list *output)
{
	char *color;

	color = NULL;
	if (!ft_strncmp(params, "red;", 4))
		color = RED;
	else if (!ft_strncmp(params, "green;", 6))
		color = GREEN;
	else if (!ft_strncmp(params, "yellow;", 7))
		color = YELLOW;
	else if (!ft_strncmp(params, "blue;", 5))
		color = BLUE;
	else if (!ft_strncmp(params, "magenta;", 8))
		color = MAGENTA;
	else if (!ft_strncmp(params, "cyan;", 5))
		color = CYAN;
	else if (!ft_strncmp(params, ";", 1))
		color = RESET;
	if (color)
	{
		if (!(color = ft_strdup(color)))
			exit(myerror("Null malloc"));
		ft_printf_buffer_add(output, (void*)color, 0);
		return ((ft_strchr(params, ';') - params) + 1);
	}
	return (-1);
}
