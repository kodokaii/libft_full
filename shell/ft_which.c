/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/09 00:33:19 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*_join_cmd_path(const char *cmd, size_t cmd_len, const char **path)
{
	char	*cmd_path;
	size_t	path_len;

	path_len = 0;
	while ((*path)[path_len] && (*path)[path_len] != ':')
		path_len++;
	cmd_path = malloc(cmd_len + path_len + 2);
	if (!cmd_path)
		return (NULL);
	ft_strlcpy(cmd_path, *path, path_len + 1);
	cmd_path[path_len] = '/';
	ft_strlcpy(cmd_path + path_len + 1, cmd, cmd_len + 1);
	(*path) += path_len;
	return (cmd_path);
}

static char	*_find_cmd_path(const char *cmd, const char *path)
{
	size_t	cmd_len;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_len = ft_strlen(cmd);
	while (*path)
	{
		path++;
		cmd_path = _join_cmd_path(cmd, cmd_len, &path);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

char	*ft_which(const char *cmd, char *const *envp)
{
	char const	*path;
	char		*cmd_path;

	cmd_path = ft_strdup(cmd);
	if (!cmd_path)
		return (NULL);
	if (access(cmd_path, X_OK))
	{
		free(cmd_path);
		cmd_path = NULL;
		if (ft_strncmp(cmd, "./", 2))
		{
			path = ft_get_envp("PATH=", envp);
			if (!path)
				return (NULL);
			path += 4;
			cmd_path = _find_cmd_path(cmd, path);
		}
	}
	return (cmd_path);
}
