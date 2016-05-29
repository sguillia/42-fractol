/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converted_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:48:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles s flags
*/

void	handle_converted_s(t_options *options, t_list *output, char *str)
{
	char flags;

	flags = options->flags;
	if ((int)ft_strlen(str) < options->field_width)
	{
		if (flags & FLAG_MIN)
			str = adjust_left(str, options->field_width);
		else if (flags & FLAG_ZERO)
			str = flag_zero_s(str, options->field_width);
		else
			str = adjust_right(str, options->field_width);
	}
	ft_printf_buffer_add(output, (void*)str, 1);
}
