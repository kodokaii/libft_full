/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 18:01:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_buf_write(t_buf *dst, t_buf *src, size_t offset)
{
	if (dst->size == INVALID_SIZE || src->size == INVALID_SIZE)
		return (NULL);
	ft_buf_alloc(dst, offset, offset + src->size);
	ft_memcpy(dst->buf + offset, src->buf, src->size);
	return (dst->buf + offset);
}
