/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/08 19:04:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_word_len(char const *str, char const *sep)
{
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && !ft_strchr(sep, str[word_len]))
		word_len++;
	return (word_len);
}

size_t	ft_count_word(char const *str, char const *sep)
{
	size_t	word_count;
	size_t	word_len;

	word_count = 0;
	while (*str)
	{
		word_len = ft_word_len(str, sep);
		if (word_len)
		{
			str += word_len;
			word_count++;
		}
		else
			str++;
	}
	return (word_count);
}
