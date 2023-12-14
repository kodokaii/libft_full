/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:56 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static pid_t	_error(t_transpipe *pipefd, char **argv)
{
	if (pipefd)
	{
		ft_close(&pipefd->in[0]);
		ft_close(&pipefd->out[1]);
	}
	perror(ft_basename(argv[0]));
	return (INVALID_PID);
}

static int	_init_pipe(int *in, t_transpipe *pipefd, int *out)
{
	if (*in != INVALID_FD)
	{
		pipefd->in[1] = INVALID_FD;
		pipefd->in[0] = *in;
	}
	else
	{
		if (pipe(pipefd->in))
			return (EXIT_FAILURE);
		*in = pipefd->in[1];
	}
	if (*out != INVALID_FD)
	{
		pipefd->out[1] = *out;
		pipefd->out[0] = INVALID_FD;
	}
	else
	{
		if (pipe(pipefd->out))
			return (EXIT_FAILURE);
		*out = pipefd->out[0];
	}
	return (EXIT_SUCCESS);
}

static pid_t	_cmd(t_transpipe *pipefd, char **argv, char **envp)
{
	ft_close(&pipefd->in[1]);
	ft_close(&pipefd->out[0]);
	if (dup2(pipefd->in[0], STDIN_FILENO) == INVALID_FD)
		return (_error(pipefd, argv));
	if (dup2(pipefd->out[1], STDOUT_FILENO) == INVALID_FD)
		return (_error(pipefd, argv));
	ft_close(&pipefd->in[0]);
	ft_close(&pipefd->out[1]);
	execve(argv[0], argv, envp);
	exit(errno);
}

pid_t	ft_execve(int *in, char **argv, char **envp, int *out)
{
	t_transpipe	pipefd;
	pid_t		pid;

	if (_init_pipe(in, &pipefd, out))
		return (_error(&pipefd, argv));
	pid = fork();
	if (pid == 0)
		_cmd(&pipefd, argv, envp);
	if (pid == INVALID_PID)
		return (_error(&pipefd, argv));
	ft_close(&pipefd.in[0]);
	ft_close(&pipefd.out[1]);
	return (pid);
}
