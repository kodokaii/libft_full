/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/31 20:14:48 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_max_int(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

t_uint	ft_max_uint(t_uint a, t_uint b)
{
	if (a < b)
		return (b);
	return (a);
}

size_t	ft_max_size(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

ssize_t	ft_max_ssize(ssize_t a, ssize_t b)
{
	if (a < b)
		return (b);
	return (a);
}

double	ft_max_double(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}
