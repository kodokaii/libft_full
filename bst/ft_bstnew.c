/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:01:17 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/13 02:05:24 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bst	*ft_bstnew(void *content)
{
	t_bst	*new;

	new = malloc(sizeof(t_bst));
	if (new)
		new->content = content;
	return (new);
}
