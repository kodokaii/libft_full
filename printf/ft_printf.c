/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/27 21:44:14 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_after_var(t_printf_format *format)
{
	if (STATE(format, PRINTF_WIDTH_SPACE) && NFLAGS(format, PRINTF_MINUS)
		&& (NSTATE(format, PRINTF_WIDTH_ZERO) || NFLAGS(format, PRINTF_ZERO)
			|| (STATE(format, PRINTF_PRECISION)
				&& FLAGS(format, PRINTF_POINT))))
		format->total_len += ft_printf_width_space(format);
	ft_putstr_fd(format->prefix, 1);
	if (STATE(format, PRINTF_WIDTH_ZERO) && FLAGS(format, PRINTF_ZERO)
		&& (NFLAGS(format, PRINTF_POINT) || NSTATE(format, PRINTF_PRECISION))
		&& STATE(format, PRINTF_DISPLAY))
		format->total_len += ft_printf_width_zero(format);
	if (STATE(format, PRINTF_PRECISION) && FLAGS(format, PRINTF_POINT)
		&& STATE(format, PRINTF_DISPLAY))
		format->total_len += ft_printf_precision(format);
}

void	ft_printf_before_var(t_printf_format *format)
{
	if (STATE(format, PRINTF_WIDTH_SPACE) && FLAGS(format, PRINTF_MINUS))
		format->total_len += ft_printf_width_space(format);
}

void	ft_printf_format(t_printf_format *format)
{
	if (format->specifier == PRINTF_CHAR)
		ft_printf_char(format);
	else if (format->specifier == PRINTF_STRING)
		ft_printf_str(format);
	else if (format->specifier == PRINTF_POINTER)
		ft_printf_ptr(format);
	else if (format->specifier == PRINTF_INT)
		ft_printf_int(format);
	else if (format->specifier == PRINTF_UNSIGNED)
		ft_printf_uint(format);
	else if (format->specifier == PRINTF_HEXA_LOW)
		ft_printf_hexa_low(format);
	else if (format->specifier == PRINTF_HEXA_UP)
		ft_printf_hexa_up(format);
	else if (format->specifier == PRINTF_PERCENTAGE)
		ft_printf_percentage(format);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		len;

	va_start(arg_list, str);
	len = ft_printf_parsing(str, &arg_list);
	va_end(arg_list);
	return (len);
}
