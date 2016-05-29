/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converted_nullc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:48:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles null character
*/

void	handle_converted_nullc(t_options *options, t_list *output)
{
	char	flags;
	char	*ret;
	int		mfw;

	mfw = options->field_width - 1;
	if (mfw < 0)
		mfw = 0;
	flags = options->flags;
	if (flags & FLAG_ZERO)
		ret = get_n_chars(mfw, '0');
	else
		ret = get_n_chars(mfw, ' ');
	ft_printf_buffer_add(output, (void*)ret, 1);
}
