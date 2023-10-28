/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 21:36:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_printf_check_flags(t_printf_format *format, t_printf_flags flags)
{
	return ((format->flags & flags) == flags);
}

t_bool	ft_printf_check_noflags(t_printf_format *format, t_printf_flags flags)
{
	return (((format->flags ^ flags) & flags) == flags);
}

t_bool	ft_printf_check_state(t_printf_format *format, t_printf_state state)
{
	return ((format->state & state) == state);
}

t_bool	ft_printf_check_nostate(t_printf_format *format, t_printf_state state)
{
	return (((format->state ^ state) & state) == state);
}

void	ft_printf_check_abs(t_printf_format *format)
{
	if ((int)format->width < 0)
	{
		format->flags |= PRINTF_MINUS;
		format->width = -format->width;
	}
	format->precision = ft_abs_int(format->precision);
}
