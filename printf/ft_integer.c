/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/27 21:43:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_printf_format *format)
{
	char	c;

	c = format->var.c;
	format->state = PRINTF_WIDTH_SPACE | PRINTF_DISPLAY;
	ft_printf_init_len(format, 1);
	ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	ft_putchar_fd(c, 1);
	ft_printf_before_var(format);
}

void	ft_printf_int(t_printf_format *format)
{
	int		n;
	t_bool	display;

	n = format->var.i;
	display = (n || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_NEGATIVE * (n < 0)
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(ft_abs_int(n), 10));
	ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	if (display)
		ft_putuint_fd(ft_abs_int(n), 1);
	ft_printf_before_var(format);
}

void	ft_printf_uint(t_printf_format *format)
{
	t_uint	n;
	t_bool	display;

	n = format->var.u;
	display = (n || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(n, 10));
	ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	if (display)
		ft_putuint_fd(n, 1);
	ft_printf_before_var(format);
}

void	ft_printf_percentage(t_printf_format *format)
{
	format->total_len = 1;
	ft_putchar_fd('%', 1);
}
