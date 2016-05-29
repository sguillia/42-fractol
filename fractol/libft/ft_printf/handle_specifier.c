/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:35:48 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_specifier(t_options *options, t_list *output)
{
	void	*arg;
	char	c;

	c = options->specifier;
	arg = get_arg(options->argpos,
			output->content,
			((t_list*)output->content)->content);
	if (c == 'd' || c == 'i')
		handle_specifier_d(options, output, arg);
	else if (c == 's')
		handle_specifier_s(options, output, arg);
	else if (c == 'c')
		handle_specifier_c(options, output, arg);
	else if (c == 'x' || c == 'o' || c == 'u')
		handle_specifier_oux(options, output, arg);
	else if (c == 'p')
		handle_specifier_p(options, output, arg);
	else if (c == 'r')
		handle_specifier_r(options, output, arg);
	else if (c == 'b')
		handle_specifier_b(options, output, arg);
}
