/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/07 19:27:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(int in, char **cmd_tab, char **envp, int out)
{
	char	**cmd;
	int		cmd_out;
	int		status;

	if (cmd_tab[0])
	{
		cmd = ft_split(cmd_tab[0], " \t");
		if (cmd && cmd_tab[1])
		{
			cmd_out = INVALID_FD;
			ft_execve(&in, cmd, envp, &cmd_out);
			ft_pipex(cmd_out, cmd_tab + 1, envp, out);
		}
		else if (cmd)
			ft_execve(&in, cmd, envp, &out);
		wait(&status);
		ft_split_free(cmd);
		return (WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
