/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 15:42:40 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**_free(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

void	ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char *sep)
{
	char		**split;
	size_t		split_count;
	size_t		i;

	split_count = ft_count_word(s, sep);
	split = malloc((split_count + 1) * sizeof(char *));
	if (split)
	{
		i = 0;
		while (i < split_count)
		{
			while (*s && ft_strchr(sep, *s))
				s++;
			split[i] = ft_strndup(s, ft_word_len(s, sep));
			if (!split[i])
				return (_free(split, i));
			while (*s && !ft_strchr(sep, *s))
				s++;
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}
