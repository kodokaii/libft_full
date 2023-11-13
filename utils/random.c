/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 21:13:57 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_llu	ft_srand(t_llu init_seed)
{
	static t_llu	seed = (t_llu)ft_srand;

	if (init_seed)
		seed = init_seed;
	return (seed);
}

int	ft_rand(void)
{
	t_llu	seed;

	seed = ft_srand(0) * 1103515245 + 12345;
	ft_srand(seed);
	return (seed % ((t_uint)INT_MAX + 1));
}
