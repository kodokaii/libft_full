/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 16:01:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s);
	dst = malloc(len + 1);
	if (dst)
	{
		dst[len] = 0;
		while (len--)
			dst[len] = (*f)(len, s[len]);
	}
	return (dst);
}
