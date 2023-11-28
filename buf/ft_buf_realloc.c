/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/28 16:34:49 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_buf_realloc(t_buf *buf, size_t new_size)
{
	if (buf->size != INVALID_SIZE)
	{
		new_size = ft_max_size(buf->size * 2, new_size);
		buf->buf = ft_realloc(buf->buf, buf->size, new_size);
		buf->size = new_size;
		if (!buf->buf)
			buf->size = INVALID_SIZE;
	}
}
