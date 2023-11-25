/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 15:38:41 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	_error(int split_count, char ***split)
{
	int	i;
	int	j;

	i = 0;
	while (i < split_count)
	{
		j = 0;
		while (split[i][j])
		{
			free(split[i][j]);
			j++;
		}
		free(split[i]);
		i++;
	}
	free(split);
	return (EXIT_FAILURE);
}

static void	_fill_argv(char **new_argv,
		int split_count, char ***split)
{
	int	i;
	int	j;

	i = 0;
	while (i < split_count)
	{
		j = 0;
		while (split[i][j])
		{
			*new_argv = split[i][j];
			new_argv++;
			j++;
		}
		free(split[i]);
		i++;
	}
	*new_argv = NULL;
	free(split);
}

int	ft_split_argv(int *argc, char ***argv)
{
	char	***split;
	char	**new_argv;
	int		new_argc;
	int		i;

	i = 0;
	new_argc = 0;
	split = malloc(*argc * sizeof(char **));
	if (!split)
		return (_error(0, split));
	while (i < *argc)
	{
		new_argc += ft_count_word((*argv)[i], " \t");
		split[i] = ft_split((*argv)[i], " \t");
		if (!split[i])
			return (_error(i, split));
		i++;
	}
	new_argv = malloc((new_argc + 1) * sizeof(char *));
	if (!new_argv)
		return (_error(*argc, split));
	_fill_argv(new_argv, *argc, split);
	*argc = new_argc;
	*argv = new_argv;
	return (EXIT_SUCCESS);
}

char	**ft_argv(char **init_argv)
{
	static char	**argv = NULL;

	if (init_argv)
		argv = init_argv;
	return (argv);
}
