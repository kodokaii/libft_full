/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/08 02:03:52 by nlaerema         ###   ########.fr       */
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

void	ft_read_line(int fd, t_buf *line, t_buf *buf, ssize_t read_size)
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
			if (buf->len < 0)
				line->len = -1;
			if (0 <= buf->len)
				ft_read_line(fd, line, buf, read_size);
		}
	}
	else if (oldbuf.buf)
		line_allocation(line, buf, &oldbuf);
	if (oldbuf.buf && line->buf)
		line->buf = ft_memcpy(line->buf - oldbuf.len, oldbuf.buf, oldbuf.len);
	free(oldbuf.buf);
}
