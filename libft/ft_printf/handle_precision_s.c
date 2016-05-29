/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:28:13 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_precision_s(t_options *options, t_list *output, char *str)
{
	char	*ret;
	int		precision;
	int		len;

	precision = options->precision;
	len = (int)ft_strlen(str);
	ret = str;
	if (precision != -1 && precision < len)
	{
		if (!(ret = ft_strndup(str, precision)))
			exit(myerror("Null malloc"));
		free(str);
	}
	handle_converted_s(options, output, ret);
}
