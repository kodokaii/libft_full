/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/08 19:06:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_free(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
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
				return (ft_split_free(split, i));
			while (*s && !ft_strchr(sep, *s))
				s++;
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}
