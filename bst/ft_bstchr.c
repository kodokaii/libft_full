/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/15 21:39:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_bstchr(t_bst *root, void *content, int (*cmp)())
{
	void	*item_find;

	item_find = NULL;
	if (root->left)
		item_find = ft_bstchr(root->left, content, cmp);
	if (!item_find && cmp(content, root->content) == 0)
		return (root);
	if (!item_find && root->right)
		item_find = ft_bstchr(root->right, content, cmp);
	return (item_find);
}
