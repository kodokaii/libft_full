/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 01:06:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*new_ptr;

	if (oldsize == newsize)
		return (ptr);
	new_ptr = malloc(newsize);
	if (new_ptr)
		ft_memcpy(new_ptr, ptr, ft_min_size(oldsize, newsize));
	free(ptr);
	return (new_ptr);
}
