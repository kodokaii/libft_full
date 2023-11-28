/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:01:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:59:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bst	*ft_bstnew(void *data)
{
	t_bst	*new;

	new = malloc(sizeof(t_bst));
	if (new)
		new->data = data;
	return (new);
}
