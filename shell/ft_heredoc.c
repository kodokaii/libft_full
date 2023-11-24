/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/24 15:59:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define FILE_TMP "/tmp/ft_heredoc.tmp"

static int	_end(t_buf *line, int heredoc_write, t_bool error)
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

	line.size = 0;
	line.buf = NULL;
	limiter_len = ft_strlen(limiter);
	heredoc_write = open(FILE_TMP, O_WRONLY | O_TRUNC | O_CREAT, 0b110100100);
	if (heredoc_write == INVALID_FD)
		return (_end(NULL, heredoc_write, FT_TRUE));
	ft_putstr_fd("ft_heredoc> ", STDOUT_FILENO);
	while (limiter_len + 1 != line.size
		|| ft_memcmp(limiter, line.buf, limiter_len))
	{
		if (line.size && ((char *)line.buf)[line.size - 1] == '\n')
			ft_putstr_fd("ft_heredoc> ", STDOUT_FILENO);
		if (write(heredoc_write, line.buf, line.size) != line.size)
			return (_end(&line, heredoc_write, FT_TRUE));
		free(line.buf);
		line = ft_gnl(STDIN_FILENO);
		if (line.size < 0)
			return (_end(&line, heredoc_write, FT_TRUE));
	}
	return (_end(&line, heredoc_write, FT_FALSE));
}
