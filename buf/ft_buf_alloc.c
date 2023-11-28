/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 18:01:35 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_buf_alloc(t_buf *buf, size_t offset, size_t size)
{
	if (buf->size == INVALID_SIZE)
		return (NULL);
	if ((size_t)buf->size < offset + size)
		ft_buf_realloc(buf, offset + size);
	if (buf->size == INVALID_SIZE)
		return (NULL);
	return (buf->buf + offset);
}
