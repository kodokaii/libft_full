/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:18 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_bstchr(t_bst *root, void *data, int (*cmp)())
{
	void	*item_find;

	item_find = NULL;
	if (root->left)
		item_find = ft_bstchr(root->left, data, cmp);
	if (!item_find && cmp(data, root->data) == 0)
		return (root);
	if (!item_find && root->right)
		item_find = ft_bstchr(root->right, data, cmp);
	return (item_find);
}
