/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:51:22 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:59:10 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bst	*ft_bstpush(t_bst **root, void *data, int (*cmp)())
{
	if (!*root)
		return (*root = ft_bstnew(data));
	if (cmp(data, (*root)->data) <= 0)
		return (ft_bstpush(&(*root)->left, data, cmp));
	return (ft_bstpush(&(*root)->right, data, cmp));
}
