/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gpu_sources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:57:04 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 22:31:13 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifdef GPU

static char	*load_file(char *ret, int fd)
{
	int		retgnl;
	char	*line;
	char	*ret_old;

	while (1)
	{
		retgnl = get_next_line(fd, &line);
		if (retgnl == 0)
			break ;
		else if (retgnl == -1)
		{
			ft_printf_fd(2, "%red;Failed to load GPU source%;\n");
			exit(1);
		}
		ret_old = ret;
		ret = ft_strjoin3(ret_old, "\n", line);
		free(ret_old);
		free(line);
	}
	close(fd);
	ret_old = ret;
	ret = ft_strjoin(ret_old, "\n");
	free(ret_old);
	return (ret);
}

static char	*try_load_file(char *filename, char *ret)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf_fd(2, "%red;Failed to open GPU source : %;%s\n", filename);
		exit(1);
	}
	ret = load_file(ret, fd);
	return (ret);
}

char		*load_gpu_sources(void)
{
	char	*ret;

	ft_check_malloc((ret = ft_strdup("#define FROM_KERNEL\n")));
	ret = try_load_file(GPU_SOURCE, ret);
	return (ret);
}

#endif
