/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converted_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:21:20 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles p flags
*/

void	handle_converted_p(t_options *options, t_list *output, char *str)
{
	char flags;

	flags = options->flags;
	str = add_prefix("0x", str, 0);
	if ((int)ft_strlen(str) < options->field_width)
	{
		if (flags & FLAG_MIN)
			str = adjust_left(str, options->field_width);
		else if ((flags & FLAG_ZERO) && options->precision == -1)
			str = flag_zero_ouxpb(str, options->field_width);
		else
			str = adjust_right(str, options->field_width);
	}
	if (flags & FLAG_UPPERCASE)
		ft_strtoupper(str);
	else
		ft_strtolower(str);
	ft_printf_buffer_add(output, (void*)str, 1);
}
