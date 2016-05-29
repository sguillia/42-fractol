/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:58:59 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/24 13:59:02 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_expo(int base, unsigned int exp)
{
	int	ret;

	if (!base)
		return (0);
	if (!exp)
		return (1);
	ret = base;
	while (--exp)
		ret *= base;
	return (ret);
}
