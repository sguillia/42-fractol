/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:43:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	%r = %s but non printable bytes are replaced by '.'
*/

void	handle_specifier_r(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	*cpy;

	if (arg == NULL && !(ret = ft_strdup("(null)")))
		exit(myerror("Null malloc"));
	else if (arg == NULL)
		;
	else if (!(ret = ft_strdup((char*)arg)))
		exit(myerror("Null malloc"));
	else
	{
		cpy = ret;
		while (*ret)
		{
			if (!ft_isprint(*ret))
				*ret = '.';
			ret++;
		}
		ret = cpy;
	}
	handle_precision_s(options, output, ret);
}
