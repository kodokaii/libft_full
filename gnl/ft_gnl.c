/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/08 01:48:09 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static t_buf	*buf_save(int fd_get, int fd_free)
{
	static t_buf	buf_save[FT_FD_MAX] = {};

	if (0 <= fd_free && fd_free < FT_FD_MAX)
	{
		free(buf_save[fd_free].buf);
		buf_save[fd_free].buf = NULL;
		buf_save[fd_free].buf = 0;
	}
	if (0 <= fd_get && fd_get < FT_FD_MAX)
		return (buf_save + fd_get);
	return (NULL);
}

t_buf	ft_gnl(int fd)
{
	t_buf			*save;
	t_buf			line;

	line.len = 0;
	line.buf = NULL;
	save = buf_save(fd, INVALID_FD);
	if (!save)
		return ((t_buf){NULL, 0});
	ft_read_line(fd, &line, save, save->len);
	return (line);
}

int	ft_close(int *fd)
{
	int	res;

	res = 0;
	buf_save(INVALID_FD, *fd);
	if (STDERR_FILENO < *fd)
	{
		res = close(*fd);
		*fd = INVALID_FD;
	}
	return (res);
}
