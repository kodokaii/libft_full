/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/09 00:34:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	execve_free(t_exec *exec)
{
	size_t	i;

	i = 0;
	while (exec->argv && exec->argv[i])
		free(exec->argv[i++]);
	if (exec->argv)
	{
		free(exec->argv);
		exec->argv = NULL;
	}
	if (exec->cmd_path)
	{
		free(exec->cmd_path);
		exec->cmd_path = NULL;
	}
}

pid_t	execve_error(t_pipe *pipefd, t_exec *exec,
			char const *cmd, t_execve_error error)
{
	execve_free(exec);
	if (pipefd)
	{
		ft_close(&pipefd->in[0]);
		ft_close(&pipefd->in[1]);
		ft_close(&pipefd->out[0]);
		ft_close(&pipefd->out[1]);
	}
	if (error == EXCV_CMD_ERROR)
		ft_dprintf(STDERR_FILENO, "%s: command not found: %s\n",
			ft_basename(ft_argv(NULL)[0]), cmd);
	if (error == EXCV_FORK_ERROR || error == EXCV_OTHER_ERROR)
		perror(ft_basename(ft_argv(NULL)[0]));
	if (error == EXCV_FORK_ERROR)
		exit(1);
	return (INVALID_PID);
}

static int	init_pipe(int *in, t_pipe *pipefd, int *out)
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

static void	cmd_execve(t_pipe *pipefd, t_exec *exec, char const *cmd)
{
	if (ft_close(&pipefd->in[1]) || ft_close(&pipefd->out[0]))
		execve_error(pipefd, exec, cmd, EXCV_FORK_ERROR);
	if (dup2(pipefd->in[0], STDIN_FILENO) == INVALID_FD)
		execve_error(pipefd, exec, cmd, EXCV_FORK_ERROR);
	if (dup2(pipefd->out[1], STDOUT_FILENO) == INVALID_FD)
		execve_error(pipefd, exec, cmd, EXCV_FORK_ERROR);
	execve(exec->cmd_path, exec->argv, exec->envp);
	execve_error(pipefd, exec, cmd, EXCV_FORK_ERROR);
}

pid_t	ft_execve(int *in, char const *cmd, char *const *envp, int *out)
{
	t_pipe	pipefd;
	t_exec	exec;
	pid_t	pid;

	exec.cmd_path = NULL;
	exec.envp = (char **)envp;
	exec.argv = ft_split(cmd, "\t ");
	if (!exec.argv)
		return (execve_error(NULL, &exec, cmd, EXCV_OTHER_ERROR));
	exec.cmd_path = ft_which(exec.argv[0], envp);
	if (!exec.cmd_path)
		return (execve_error(NULL, &exec, cmd, EXCV_CMD_ERROR));
	if (init_pipe(in, &pipefd, out))
		return (execve_error(&pipefd, &exec, cmd, EXCV_OTHER_ERROR));
	pid = fork();
	if (pid == 0)
		cmd_execve(&pipefd, &exec, cmd);
	if (pid == INVALID_PID)
		return (execve_error(&pipefd, &exec, cmd, EXCV_OTHER_ERROR));
	execve_free(&exec);
	if (ft_close(&pipefd.in[0]) || ft_close(&pipefd.out[1]))
		return (execve_error(&pipefd, &exec, cmd, EXCV_OTHER_ERROR));
	return (pid);
}
