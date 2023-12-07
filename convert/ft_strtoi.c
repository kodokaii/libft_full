/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/07 03:22:48 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	_get_nb(const char **str, int sign)
{
	long	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res *= 10;
		res += **str - '0';
		if (res * sign < INT_MIN || INT_MAX < res * sign)
		{
			errno = ERANGE;
			if (sign < 0)
				return (INT_MIN);
			return (INT_MAX);
		}
		(*str)++;
	}
	return (res * sign);
}

int	ft_strtoi(const char *str, char **endptr)
{
	int		res;
	int		sign;

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
	res = _get_nb(&str, sign);
	if (endptr)
		*endptr = (char *)str;
	return (res);
}
