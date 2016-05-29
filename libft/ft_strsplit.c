/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:38:23 by sguillia          #+#    #+#             */
/*   Updated: 2015/12/13 14:56:41 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnumsplits(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (!*s)
		return (0);
	while (*s && *s != c)
		s++;
	return (1 + ft_strnumsplits(s, c));
}

char		**free_tab(char **mytab)
{
	int i;

	i = -1;
	while (mytab[++i])
		free(mytab[i]);
	free(mytab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		num_splits;
	int		cpt_splits;
	char	**mytab;
	char	*possible_end;
	char	*end;

	num_splits = ft_strnumsplits(s, c);
	if (!(mytab = (char**)malloc((num_splits + 1) * sizeof(*mytab))))
		return (NULL);
	mytab[num_splits] = NULL;
	cpt_splits = -1;
	while (++cpt_splits < num_splits)
	{
		while (*s == c)
			s++;
		possible_end = ft_strchr(s, c);
		end = possible_end ? possible_end : ft_strchr(s, '\0');
		if (!(mytab[cpt_splits] = ft_strsub(s, 0, end - s)))
			return (free_tab(mytab));
		s = end;
	}
	return (mytab);
}
