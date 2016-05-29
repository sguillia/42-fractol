/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:43:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		handle_specifier_b(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	lmod;

	lmod = options->lmod;
	ret = NULL;
	if (!lmod)
		ret = ft_uintmaxtoa_base((unsigned int)arg, 2);
	else if (lmod == LMOD_HH)
		ret = ft_itoa_base((unsigned char)arg, 2);
	else if (lmod == LMOD_H)
		ret = ft_itoa_base((unsigned short)arg, 2);
	else if (lmod == LMOD_LL)
		ret = ft_ulltoa_base((unsigned long long)arg, 2);
	else if (lmod == LMOD_L)
		ret = ft_ulltoa_base((unsigned long)arg, 2);
	else if (lmod == LMOD_J)
		ret = ft_uintmaxtoa_base((uintmax_t)arg, 2);
	else if (lmod == LMOD_Z)
		ret = ft_sizettoa_base((size_t)arg, 2);
	if (ret == NULL)
		exit(myerror("Null malloc"));
	handle_precision_b(options, output, ret);
}
