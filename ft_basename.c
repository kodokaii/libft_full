/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:31 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_basename(char const *s)
{
	char const	*name;

	name = ft_strrchr(s, '/');
	if (!name)
		name = s;
	else
		name++;
	return (name);
}
