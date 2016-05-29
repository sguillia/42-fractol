/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:43:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_specifier_d(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	lmod;

	lmod = options->lmod;
	ret = NULL;
	if (!lmod)
		ret = ft_itoa((int)arg);
	else if (lmod == LMOD_HH)
		ret = ft_itoa((signed char)arg);
	else if (lmod == LMOD_H)
		ret = ft_itoa((short)arg);
	else if (lmod == LMOD_LL)
		ret = ft_lltoa_base((long long)arg, 10);
	else if (lmod == LMOD_L)
		ret = ft_lltoa_base((long)arg, 10);
	else if (lmod == LMOD_J)
		ret = ft_intmaxtoa_base((intmax_t)arg, 10);
	else if (lmod == LMOD_Z)
		ret = ft_intmaxtoa_base((intmax_t)arg, 10);
	if (ret == NULL)
		exit(myerror("Null malloc"));
	handle_precision_d(options, output, ret);
}
