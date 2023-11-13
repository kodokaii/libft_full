/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 01:25:19 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static void	update_len(t_buf *oldbuf, t_buf *line)
{
	ssize_t	len;

	len = 0;
	if (0 < oldbuf->size && oldbuf->buf)
	{
		while (len < oldbuf->size && ((char *)oldbuf->buf)[len] != '\n')
			len++;
		if (len != oldbuf->size)
			oldbuf->size = len + 1;
		line->size += oldbuf->size;
	}
}

static void	line_allocation(t_buf *line, t_buf *buf, t_buf *oldbuf)
{
	if (line->size)
		line->buf = malloc(line->size + 1);
	if (line->buf)
	{
		((char *)line->buf)[line->size] = '\0';
		line->buf += line->size;
		buf->size -= oldbuf->size;
		buf->buf = ft_memdup(oldbuf->buf + oldbuf->size, buf->size);
	}
	if (!line->buf || (!buf->buf && buf->size))
	{
		line->size = INVALID_SIZE;
		line->buf = NULL;
		buf->size = INVALID_SIZE;
		buf->buf = NULL;
	}
}

void	ft_read_line(int fd, t_buf *line, t_buf *buf, ssize_t read_size)
{
	t_buf	oldbuf;

	oldbuf = *buf;
	update_len(&oldbuf, line);
	if (oldbuf.size == read_size)
	{
		read_size = ft_max_ssize(read_size, FT_BUFFER_SIZE) * 2;
		buf->buf = malloc(read_size);
		if (buf->buf)
		{
			buf->size = read(fd, buf->buf, read_size);
			if (buf->size < 0)
				line->size = INVALID_SIZE;
			if (0 <= buf->size)
				ft_read_line(fd, line, buf, read_size);
		}
	}
	else if (oldbuf.buf)
		line_allocation(line, buf, &oldbuf);
	if (oldbuf.buf && line->buf)
		line->buf = ft_memcpy(line->buf - oldbuf.size, oldbuf.buf, oldbuf.size);
	free(oldbuf.buf);
}
