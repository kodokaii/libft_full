/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 01:55:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putint_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_putuint_fd(n, fd);
}

void	ft_putuint_fd(t_uint n, int fd)
{
	if (n / 10)
		ft_putuint_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}
