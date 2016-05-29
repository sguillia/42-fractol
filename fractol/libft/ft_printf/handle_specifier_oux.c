/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_oux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:43:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(char specifier)
{
	if (specifier == 'o')
		return (8);
	else if (specifier == 'x')
		return (16);
	else
		return (10);
}

void		handle_specifier_oux(t_options *options, t_list *output, void *arg)
{
	char	*ret;
	char	lmod;
	int		base;

	lmod = options->lmod;
	ret = NULL;
	base = get_base(options->specifier);
	if (!lmod)
		ret = ft_uintmaxtoa_base((unsigned int)arg, base);
	else if (lmod == LMOD_HH)
		ret = ft_itoa_base((unsigned char)arg, base);
	else if (lmod == LMOD_H)
		ret = ft_itoa_base((unsigned short)arg, base);
	else if (lmod == LMOD_LL)
		ret = ft_ulltoa_base((unsigned long long)arg, base);
	else if (lmod == LMOD_L)
		ret = ft_ulltoa_base((unsigned long)arg, base);
	else if (lmod == LMOD_J)
		ret = ft_uintmaxtoa_base((uintmax_t)arg, base);
	else if (lmod == LMOD_Z)
		ret = ft_sizettoa_base((size_t)arg, base);
	if (ret == NULL)
		exit(myerror("Null malloc"));
	handle_precision_oux(options, output, ret);
}
