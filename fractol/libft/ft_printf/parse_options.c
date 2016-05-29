/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:58:33 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*parse_options(char *params, t_options *options, t_list *output)
{
	params = parse_argpos(params, options, output);
	params = parse_flags(params, options);
	params = parse_field_width(params, options, output);
	check_field_width(options);
	params = parse_precision(params, options, output);
	params = parse_casters(params, options);
	return (params);
}
