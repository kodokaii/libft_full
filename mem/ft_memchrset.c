/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/08 15:44:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchrset(void const *s, void const *set,
			size_t size_s, size_t size_set)
{
	size_t	i;

	i = 0;
	while (i < size_s)
	{
		if (ft_memchr(set, ((t_byte *)s)[i], size_set))
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
