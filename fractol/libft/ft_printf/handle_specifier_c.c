/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:55:52 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_specifier_c(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	tmp[5];
	char	lmod;

	lmod = options->lmod;
	if ((unsigned int)arg == 0)
	{
		((t_list*)output->content)->content_size++;
		handle_precision_nullc(options, output);
		return ;
	}
	if (lmod == LMOD_L)
	{
		ft_wchar_to_str(tmp, (unsigned int)arg);
		if (!(ret = ft_strdup(tmp)))
			exit(myerror("Null malloc"));
	}
	else
	{
		if (!(ret = ft_strnew(1)))
			exit(myerror("Null malloc"));
		*ret = (char)arg;
	}
	handle_precision_s(options, output, ret);
}
