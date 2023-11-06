/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/06 15:51:53 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

# define PRINTF_SPECIFIER	"cspdiuxX%"
# define PRINTF_FLAGS		"-+ #0"

# define FLAGS	ft_printf_check_flags
# define NFLAGS	ft_printf_check_noflags
# define STATE	ft_printf_check_state
# define NSTATE	ft_printf_check_nostate

typedef enum e_printf_specifier
{
	PRINTF_SPECIFIER_NONE	= 0,
	PRINTF_CHAR				= 1,
	PRINTF_STRING			= 2,
	PRINTF_POINTER			= 3,
	PRINTF_INT				= 4,
	PRINTF_UNSIGNED			= 5,
	PRINTF_HEXA_LOW			= 6,
	PRINTF_HEXA_UP			= 7,
	PRINTF_PERCENTAGE		= 8
}	t_printf_specifier;

typedef enum e_printf_flags
{
	PRINTF_FLAG_NONE		= 0,
	PRINTF_PLUS				= 1,
	PRINTF_MINUS			= 2,
	PRINTF_SPACE			= 4,
	PRINTF_HASH				= 8,
	PRINTF_ZERO				= 16,
	PRINTF_POINT			= 32
}	t_printf_flags;

typedef enum e_printf_state
{
	PRINTF_STATE_NONE		= 0,
	PRINTF_PREFIX			= 1,
	PRINTF_PREFIX_HASH		= 2,
	PRINTF_WIDTH_SPACE		= 4,
	PRINTF_WIDTH_ZERO		= 8,
	PRINTF_PRECISION		= 16,
	PRINTF_NEGATIVE			= 32,
	PRINTF_DISPLAY			= 64
}	t_printf_state;

typedef union u_printf_var
{
	char	c;
	char	*s;
	void	*p;
	int		i;
	t_uint	u;
	t_uint	x;
}	t_printf_var;

typedef struct s_printf_format
{
	t_printf_var		var;
	t_printf_flags		flags;
	t_printf_specifier	specifier;
	t_printf_state		state;
	t_uint				var_len;
	t_uint				prefix_len;
	t_uint				total_len;
	t_uint				width;
	t_uint				precision;
	char				*prefix;
}	t_printf_format;

void	ft_printf_after_var(t_printf_format *format, int fd);
void	ft_printf_before_var(t_printf_format *format, int fd);
void	ft_printf_format(t_printf_format *format, int fd);
t_uint	ft_printf_parsing(const char *str, va_list *arg, int fd);

t_bool	ft_printf_check_flags(t_printf_format *format, t_printf_flags flags);
t_bool	ft_printf_check_noflags(t_printf_format *format, t_printf_flags flags);
t_bool	ft_printf_check_state(t_printf_format *format, t_printf_state state);
t_bool	ft_printf_check_nostate(t_printf_format *format, t_printf_state state);
void	ft_printf_check_abs(t_printf_format *format);

void	ft_printf_init_len(t_printf_format *format, t_uint len);
void	ft_printf_init_prefix(t_printf_format *format, char *hash_prefix);
t_uint	ft_printf_width_space(t_printf_format *format, int fd);
t_uint	ft_printf_width_zero(t_printf_format *format, int fd);
t_uint	ft_printf_precision(t_printf_format *format, int fd);

void	ft_printf_char(t_printf_format *format, int fd);
void	ft_printf_str(t_printf_format *format, int fd);
void	ft_printf_ptr(t_printf_format *format, int fd);
void	ft_printf_int(t_printf_format *format, int fd);
void	ft_printf_uint(t_printf_format *format, int fd);
void	ft_printf_hexa_low(t_printf_format *format, int fd);
void	ft_printf_hexa_up(t_printf_format *format, int fd);
void	ft_printf_percentage(t_printf_format *format, int fd);

#endif
