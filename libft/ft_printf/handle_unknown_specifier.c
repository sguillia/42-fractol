/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unknown_specifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:14:34 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	If the specifier is unknown, argpos was still incrementd.
**	Line 24 counteracts it by decrementing argpos for next modulo parsing
*/

void	handle_unknown_specifier(t_options *options, t_list *output)
{
	char	*str;

	output->content_size--;
	if (!(str = ft_strndup(&options->specifier, 1)))
		exit(myerror("Null malloc"));
	handle_converted_s(options, output, str);
}
