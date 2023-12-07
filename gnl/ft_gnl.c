/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/07 05:18:13 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static t_buf	*_save(int fd_get, int fd_free)
{
	static t_buf	buf_save[FD_MAX] = {};

	if (0 <= fd_free && fd_free < FD_MAX)
	{
		free(buf_save[fd_free].buf);
		buf_save[fd_free].buf = NULL;
		buf_save[fd_free].size = 0;
	}
	if (0 <= fd_get && fd_get < FD_MAX)
		return (buf_save + fd_get);
	return (NULL);
}

t_buf	ft_gnl(int fd)
{
	t_buf			*save;
	t_buf			line;

	line.size = 0;
	line.buf = NULL;
	save = _save(fd, INVALID_FD);
	if (!save)
		return ((t_buf){NULL, 0});
	ft_read_line(fd, &line, save, save->size);
	return (line);
}

int	ft_close(int *fd)
{
	int	res;

	res = 0;
	_save(INVALID_FD, *fd);
	if (STDERR_FILENO < *fd)
	{
		res = close(*fd);
		*fd = INVALID_FD;
	}
	return (res);
}
