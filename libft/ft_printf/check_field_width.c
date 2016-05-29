/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:13:39 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/02 14:32:52 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles the case where the specified MFW is negative
*/

void	check_field_width(t_options *options)
{
	if (options->field_width < 0)
	{
		options->field_width *= -1;
		options->flags |= FLAG_MIN;
	}
}
