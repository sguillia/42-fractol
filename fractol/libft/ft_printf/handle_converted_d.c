/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converted_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:21:20 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles flags for d specifier
*/

void	handle_converted_d(t_options *options, t_list *output, char *str)
{
	char flags;

	flags = options->flags;
	if (flags & FLAG_PLUS && *str != '-')
		str = add_prefix("+", str, 0);
	else if (flags & FLAG_SPACE && *str != '-')
		str = add_prefix(" ", str, 0);
	if ((int)ft_strlen(str) < options->field_width)
	{
		if (flags & FLAG_MIN)
			str = adjust_left(str, options->field_width);
		else if ((flags & FLAG_ZERO) && options->precision == -1)
			str = flag_zero_d(str, options->field_width);
		else
			str = adjust_right(str, options->field_width);
	}
	ft_printf_buffer_add(output, (void*)str, 1);
}
