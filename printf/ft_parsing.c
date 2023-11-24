/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/24 15:57:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf_flags	_get_flags(char c)
{
	if (c == '+')
		return (PRINTF_PLUS);
	if (c == '-')
		return (PRINTF_MINUS);
	if (c == ' ')
		return (PRINTF_SPACE);
	if (c == '#')
		return (PRINTF_HASH);
	if (c == '.')
		return (PRINTF_POINT);
	if (c == '0')
		return (PRINTF_ZERO);
	return (PRINTF_FLAG_NONE);
}

static t_printf_specifier	_get_specifier(char c)
{
	if (c == 'c')
		return (PRINTF_CHAR);
	if (c == 's')
		return (PRINTF_STRING);
	if (c == 'p')
		return (PRINTF_POINTER);
	if (c == 'd' || c == 'i')
		return (PRINTF_INT);
	if (c == 'u')
		return (PRINTF_UNSIGNED);
	if (c == 'x')
		return (PRINTF_HEXA_LOW);
	if (c == 'X')
		return (PRINTF_HEXA_UP);
	if (c == '%')
		return (PRINTF_PERCENTAGE);
	return (PRINTF_SPECIFIER_NONE);
}

static t_printf_var	_get_var(t_printf_specifier specifier, va_list *arg_list)
{
	t_printf_var	var;

	var.p = NULL;
	if (specifier == PRINTF_CHAR)
		var.c = va_arg(*arg_list, int);
	else if (specifier == PRINTF_STRING)
		var.s = va_arg(*arg_list, char *);
	else if (specifier == PRINTF_POINTER)
		var.p = va_arg(*arg_list, void *);
	else if (specifier == PRINTF_INT)
		var.i = va_arg(*arg_list, int);
	else if (specifier == PRINTF_UNSIGNED)
		var.u = va_arg(*arg_list, unsigned int);
	else if (specifier == PRINTF_HEXA_LOW || specifier == PRINTF_HEXA_UP)
		var.x = va_arg(*arg_list, unsigned int);
	return (var);
}

static void	_get_format(const char **str,
			va_list *arg_list, t_printf_format *format)
{
	char	*current;

	current = (char *)*str + 1;
	while (ft_strchr(PRINTF_FLAGS, *current) && *current)
		format->flags |= _get_flags(*current++);
	if (*current == '*' && current++)
		format->width = va_arg(*arg_list, int);
	else if (ft_isdigit(*current))
		format->width = ft_strtoi(current, &current);
	if (*current == '.')
	{
		format->flags |= _get_flags(*current++);
		if (*current == '*' && current++)
			format->precision = va_arg(*arg_list, int);
		else if (ft_isdigit(*current))
			format->precision = ft_strtoi(current, &current);
	}
	format->specifier = _get_specifier(*current);
	if (ft_strchr(PRINTF_SPECIFIER, *current) && *current)
	{
		format->var = _get_var(format->specifier, arg_list);
		*str = current;
	}
}

t_uint	ft_printf_parsing(const char *str, va_list *arg_list, int fd)
{
	t_printf_format	format;
	t_uint			len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&format, sizeof(t_printf_format));
			_get_format(&str, arg_list, &format);
			ft_printf_format(&format, fd);
			len += format.total_len;
		}
		else
		{
			ft_putchar_fd(*str, fd);
			len++;
		}
		str++;
	}
	return (len);
}
