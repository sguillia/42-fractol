/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modulo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:56:19 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	get_options
**	Inits options struct
*/

static t_options	*get_options(void)
{
	t_options *ret;

	if (!(ret = (t_options*)malloc(sizeof(*ret))))
		exit(myerror("Null malloc"));
	ret->argpos = 0;
	ret->flags = 0;
	ret->field_width = 0;
	ret->precision = -1;
	ret->lmod = 0;
	ret->specifier = 0;
	ret->stopflag = 0;
	ret->color = NULL;
	return (ret);
}

/*
**	Frees memory and returns desired value
*/

static char			*free_all(void *addr1, void *addr2, char *ret)
{
	if (addr1)
		free(addr1);
	if (addr2)
		free(addr2);
	return (ret);
}

/*
**	Checks for malloc failure
*/

static void			check_malloc(char *str)
{
	if (!str)
		exit(myerror("Null malloc"));
}

/*
**	Handles one modulo in the input format
**	- parse color
**	- parse specifier
**	- parse options
**	- handles specifier
**	- return appropriate format position
*/

char				*handle_modulo(char *format, t_list *output)
{
	t_options	*options;
	int			i;
	char		*params;
	char		*ini_params;

	if ((i = parse_color(format, output)) != -1)
		return (format + i);
	i = 0;
	while (format[i] && ft_strchr("0123456789#+- '$.*hljz", format[i]))
		i++;
	if (!format[i])
		return (&format[i]);
	options = get_options();
	options->specifier = format[i];
	check_malloc(ini_params = ft_strsub(format, 0, i));
	params = parse_options(ini_params, options, output);
	if (options->stopflag)
		return (free_all(options, ini_params, format + (params - ini_params)));
	parse_aliases(options);
	if (!ft_strchr("spdiouxcpbr", options->specifier))
		handle_unknown_specifier(options, output);
	else
		handle_specifier(options, output);
	return (free_all(options, ini_params, format + i + 1));
}
