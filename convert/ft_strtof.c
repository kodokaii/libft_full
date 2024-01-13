/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/01/13 20:00:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	_decimal_part(const char **str)
{
	double	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res *= 10;
		res += **str - '0';
		(*str)++;
	}
	return (res);
}

static double	_fractional_part(const char **str)
{
	double	res;
	double	mod;

	res = 0;
	mod = 10;
	while (ft_isdigit(**str))
	{
		res += (**str - '0') / mod;
		mod *= 10;
		(*str)++;
	}
	return (res);
}

double	ft_strtof(const char *str, char **endptr)
{
	double	res;
	double	sign;

	if (endptr)
		*endptr = (char *)str;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	res = _decimal_part(&str);
	if (*str == '.')
	{
		str++;
		res += _fractional_part(&str);
	}
	if (*endptr)
		*endptr = (char *)str;
	return (res * sign);
}
