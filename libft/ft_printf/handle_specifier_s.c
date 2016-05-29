/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:43:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_specifier_s(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	lmod;

	lmod = options->lmod;
	if (arg == NULL && !(ret = ft_strdup("(null)")))
		exit(myerror("Null malloc"));
	else if (arg == NULL)
		;
	else if (lmod == LMOD_L)
		ret = ft_wstr_to_str((unsigned int*)arg);
	else if (!(ret = ft_strdup((char*)arg)))
		exit(myerror("Null malloc"));
	handle_precision_s(options, output, ret);
}
