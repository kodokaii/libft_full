/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/09 00:34:18 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FILE_TMP "/tmp/ft_heredoc.tmp"

static int	heredoc_exit(t_buf *line, int heredoc_write, t_bool error)
{
	int					heredoc_read;

	heredoc_read = INVALID_FD;
	if (line)
		free(line->buf);
	if (!error)
		heredoc_read = open(FILE_TMP, O_RDWR);
	if (error || heredoc_read == INVALID_FD)
		perror("heredoc");
	unlink(FILE_TMP);
	ft_close(&heredoc_write);
	return (heredoc_read);
}

int	ft_get_heredoc(char const *limiter)
{
	ssize_t	limiter_len;
	t_buf	line;
	int		heredoc_write;

	line.len = 0;
	line.buf = NULL;
	limiter_len = ft_strlen(limiter);
	heredoc_write = open(FILE_TMP, O_WRONLY | O_TRUNC | O_CREAT, 0b110100100);
	if (heredoc_write == INVALID_FD)
		return (heredoc_exit(NULL, heredoc_write, FT_TRUE));
	while (limiter_len + 1 != line.len
		|| ft_memcmp(limiter, line.buf, limiter_len))
	{
		ft_putstr_fd("ft_heredoc> ", STDOUT_FILENO);
		if (write(heredoc_write, line.buf, line.len) != line.len)
			return (heredoc_exit(&line, heredoc_write, FT_TRUE));
		free(line.buf);
		line = ft_gnl(STDIN_FILENO);
		if (line.len < 0)
			return (heredoc_exit(&line, heredoc_write, FT_TRUE));
	}
	return (heredoc_exit(&line, heredoc_write, FT_FALSE));
}
