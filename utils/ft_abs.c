/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/11 17:05:57 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_byte	ft_abs_char(t_byte n)
{
	if ((char)n < 0)
		return (-n);
	return (n);
}

t_uint	ft_abs_int(t_uint n)
{
	if ((int)n < 0)
		return (-n);
	return (n);
}

float	ft_abs_float(float n)
{
	if (n < 0.0f)
		return (-n);
	return (n);
}

double	ft_abs_double(double n)
{
	if (n < 0.0L)
		return (-n);
	return (n);
}
