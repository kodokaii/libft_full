/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:51:22 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/15 21:38:50 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bst	*ft_bstpush(t_bst **root, void *content, int (*cmp)())
{
	if (!*root)
		return (*root = ft_bstnew(content));
	if (cmp(content, (*root)->content) <= 0)
		return (ft_bstpush(&(*root)->left, content, cmp));
	return (ft_bstpush(&(*root)->right, content, cmp));
}
