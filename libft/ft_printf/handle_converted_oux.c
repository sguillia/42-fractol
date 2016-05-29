/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converted_oux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:21:20 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles flags for o, u and x specifiers
**	is_zero returns one if str is equivalent to zero ("", "0", "00", ...)
*/

static int	is_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void		handle_converted_oux(t_options *options, t_list *output, char *str)
{
	char flags;

	flags = options->flags;
	if (flags & FLAG_HASH && options->specifier == 'x' && !is_zero(str))
		str = add_prefix("0x", str, 0);
	else if ((flags & FLAG_HASH) && options->specifier == 'o' && *str != '0')
		str = add_prefix("0", str, 0);
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
