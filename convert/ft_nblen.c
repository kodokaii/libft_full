/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 02:15:16 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_uint	ft_bytelen(t_byte n, t_byte base)
{
	t_uint	len;

	len = 1;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}

t_uint	ft_intlen(int n, int base)
{
	t_uint	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}

t_uint	ft_uintlen(t_uint n, int base)
{
	t_uint	len;

	len = 1;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}

t_uint	ft_llulen(t_llu n, int base)
{
	t_uint	len;

	len = 1;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}
