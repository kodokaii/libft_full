/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/09 00:32:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(int in, char *const *cmd, char *const *envp, int out)
{
	int			cmd_out;
	int			status;

	if (cmd[0])
	{
		if (cmd[1])
		{
			cmd_out = INVALID_FD;
			if (ft_execve(&in, cmd[0], envp, &cmd_out) == INVALID_PID)
				cmd_out = in;
			ft_pipex(cmd_out, cmd + 1, envp, out);
		}
		else if (ft_execve(&in, cmd[0], envp, &out) == INVALID_PID)
			return (EXIT_FAILURE);
		wait(&status);
		return (WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
