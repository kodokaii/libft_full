/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/06 15:50:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init_len(t_printf_format *format, t_uint len)
{
	if (STATE(format, PRINTF_DISPLAY))
		format->var_len = len;
	format->total_len += format->var_len;
}

void	ft_printf_init_prefix(t_printf_format *format, char *hash_prefix)
{
	if (STATE(format, PRINTF_NEGATIVE) && STATE(format, PRINTF_DISPLAY)
		&& STATE(format, PRINTF_PREFIX))
		format->prefix = "-";
	else if (FLAGS(format, PRINTF_PLUS) && STATE(format, PRINTF_DISPLAY)
		&& STATE(format, PRINTF_PREFIX))
		format->prefix = "+";
	else if (FLAGS(format, PRINTF_SPACE) && STATE(format, PRINTF_DISPLAY)
		&& STATE(format, PRINTF_PREFIX))
		format->prefix = " ";
	else if (FLAGS(format, PRINTF_HASH) && STATE(format, PRINTF_DISPLAY)
		&& STATE(format, PRINTF_PREFIX_HASH))
		format->prefix = hash_prefix;
	else
		format->prefix = "";
	format->prefix_len = ft_strlen(format->prefix);
	format->total_len += format->prefix_len;
}

t_uint	ft_printf_width_space(t_printf_format *format, int fd)
{
	t_uint	len;
	t_uint	total_len;

	len = 0;
	total_len = format->var_len;
	if (STATE(format, PRINTF_PRECISION) && FLAGS(format, PRINTF_POINT))
		total_len = ft_max_uint(format->precision, total_len);
	total_len += format->prefix_len;
	while (total_len + len < format->width)
	{
		ft_putchar_fd(' ', fd);
		len++;
	}
	return (len);
}

t_uint	ft_printf_width_zero(t_printf_format *format, int fd)
{
	t_uint	len;

	len = 0;
	while (format->var_len + format->prefix_len + len < format->width)
	{
		ft_putchar_fd('0', fd);
		len++;
	}
	return (len);
}

t_uint	ft_printf_precision(t_printf_format *format, int fd)
{
	t_uint	len;

	len = 0;
	while (format->var_len + len < format->precision)
	{
		ft_putchar_fd('0', fd);
		len++;
	}
	return (len);
}
