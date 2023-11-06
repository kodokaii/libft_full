/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/06 15:54:32 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa_low(t_printf_format *format, int fd)
{
	t_uint	x;
	t_bool	display;

	x = format->var.x;
	display = (x || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX_HASH
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(x, 16));
	if (x)
		ft_printf_init_prefix(format, "0x");
	else
		ft_printf_init_prefix(format, "");
	ft_printf_after_var(format, fd);
	if (display)
		ft_putuint_base_fd(x, "0123456789abcdef", fd);
	ft_printf_before_var(format, fd);
}

void	ft_printf_hexa_up(t_printf_format *format, int fd)
{
	t_uint	x;
	t_bool	display;

	x = format->var.x;
	display = (x || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX_HASH
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(x, 16));
	if (x)
		ft_printf_init_prefix(format, "0X");
	else
		ft_printf_init_prefix(format, "");
	ft_printf_after_var(format, fd);
	if (display)
		ft_putuint_base_fd(x, "0123456789ABCDEF", fd);
	ft_printf_before_var(format, fd);
}
