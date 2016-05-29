/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_numbytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:58:29 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:58:35 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wchar_numbytes(unsigned int c)
{
	int size;

	size = 1;
	while (c >>= 1)
		size++;
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}
