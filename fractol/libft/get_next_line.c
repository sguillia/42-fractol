/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 20:36:54 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/18 20:47:45 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*increase_buf(int const fd, char *oldbuf, int *ret_val)
{
	char	tmp[BUFF_SIZE + 1];
	char	*newbuf;

	*ret_val = read(fd, tmp, BUFF_SIZE);
	tmp[*ret_val] = '\0';
	newbuf = ft_strjoin(oldbuf, tmp);
	ft_strdel(&oldbuf);
	return (newbuf);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (!*buf)
		buf = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		buf = increase_buf(fd, buf, &ret);
	}
	return (ret);
}
