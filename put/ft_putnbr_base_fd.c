/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 18:00:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_put_rec(t_llu nbr, char *base, size_t base_sz, int fd)
{
	if (nbr / base_sz)
		ft_put_rec(nbr / base_sz, base, base_sz, fd);
	ft_putchar_fd(base[nbr % base_sz], 1);
}

void	ft_putint_base_fd(int n, char *base, int fd)
{
	if (base[0] && base[1])
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		ft_put_rec((t_uint)n, base, ft_strlen(base), fd);
	}
}

void	ft_putuint_base_fd(t_uint n, char *base, int fd)
{
	if (base[0] && base[1])
		ft_put_rec(n, base, ft_strlen(base), fd);
}

void	ft_putllu_base_fd(t_llu n, char *base, int fd)
{
	if (base[0] && base[1])
		ft_put_rec(n, base, ft_strlen(base), fd);
}
