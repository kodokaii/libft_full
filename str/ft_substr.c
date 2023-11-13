/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 01:26:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen(s);
	start = ft_min_size(src_len, start);
	len = ft_min_size(src_len - start, len);
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
