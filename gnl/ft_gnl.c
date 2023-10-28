/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/28 12:28:49 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static void	update_len(t_buf *oldbuf, t_buf *line)
{
	ssize_t	len;

	len = 0;
	if (0 < oldbuf->len && oldbuf->buf)
	{
		while (len < oldbuf->len && oldbuf->buf[len] != '\n')
			len++;
		if (len != oldbuf->len)
			oldbuf->len = len + 1;
		line->len += oldbuf->len;
	}
}

static void	line_allocation(t_buf *line, t_buf *buf, t_buf *oldbuf)
{
	if (line->len)
		line->buf = malloc(line->len + 1);
	if (line->buf)
	{
		line->buf[line->len] = '\0';
		line->buf += line->len;
		buf->len -= oldbuf->len;
		buf->buf = ft_memdup(oldbuf->buf + oldbuf->len, buf->len);
	}
	if (!line->buf || (!buf->buf && buf->len))
	{
		line->len = 0;
		line->buf = NULL;
		buf->len = 0;
		buf->buf = NULL;
	}
}

static void	read_line(int fd, t_buf *line, t_buf *buf, ssize_t read_size)
{
	t_buf	oldbuf;

	oldbuf = *buf;
	update_len(&oldbuf, line);
	if (oldbuf.len == read_size)
	{
		read_size = ft_max_ssize(read_size, FT_BUFFER_SIZE) * 2;
		buf->buf = malloc(read_size);
		if (buf->buf)
		{
			buf->len = read(fd, buf->buf, read_size);
			if (0 <= buf->len)
				read_line(fd, line, buf, read_size);
		}
	}
	else if (oldbuf.buf)
		line_allocation(line, buf, &oldbuf);
	if (oldbuf.buf && line->buf)
		line->buf = ft_memcpy(line->buf - oldbuf.len, oldbuf.buf, oldbuf.len);
	free(oldbuf.buf);
}

t_buf	ft_gnl(int fd)
{
	static t_buf	saves[FT_FD_MAX] = {};
	t_buf			line;

	line.len = 0;
	line.buf = NULL;
	if (fd < 0)
	{
		if (fd < -2)
		{
			free(saves[-fd].buf);
			saves[-fd].buf = NULL;
			saves[-fd].len = 0;
		}
		return ((t_buf){NULL, 0});
	}
	read_line(fd, &line, saves + fd, saves[fd].len);
	return (line);
}

void	ft_close(int fd)
{
	if (0 <= fd)
		ft_gnl(-fd);
	if (2 < fd)
		close(fd);
}
