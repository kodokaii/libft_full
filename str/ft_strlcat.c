/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/16 16:24:37 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	size -= dst_len;
	while (src_len + 1 < size && src[src_len])
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (size)
		dst[dst_len + src_len] = 0;
	while (src[src_len])
		src_len++;
	return (dst_len + src_len);
}
