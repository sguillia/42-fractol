/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:37:20 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:35:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Recursively frees all argument links
*/

static void	free_args(t_list *lst)
{
	t_list *next;

	if (lst)
	{
		next = lst->next;
		free(lst);
		free_args(next);
	}
}

/*
**	Ends ft_printf function (because of norm's line number limitation)
*/

static int	end_ft_printf(t_list *output, t_list *args)
{
	t_list *next;
	size_t nb_nullchars;

	next = output->next;
	nb_nullchars = args->content_size;
	free_args(args);
	free(output);
	return (ft_lstprintstr(next) + nb_nullchars);
}

/*
**	output is the list of strings to write
**	but output's first link is:
**	  -> content		=	args
**	  -> content_size	=	current va_arg position
**	args is the list of arguments (parameters)
**	but args's first link is :
**	  -> content		=	&ap
**	  -> content_size	=	number of null characters (%c == 0)
*/

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_list	*args;
	t_list	*output;

	va_start(ap, format);
	if (!(args = ft_lstnew(NULL, 0)))
		return (-1);
	if (!(output = ft_lstnew(NULL, 0)))
		return (-1);
	output->content = (void*)args;
	args->content = &ap;
	args->content_size = 0;
	output->content_size = 1;
	while (*format)
	{
		format = handle_nonmodulo(format, output);
		if (*format)
			format = (const char*)handle_modulo((char*)++format, output);
	}
	va_end(ap);
	return (end_ft_printf(output, args));
}
