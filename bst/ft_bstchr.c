/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/13 02:17:05 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_bstchr(t_bst *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*item_find;

	item_find = NULL;
	if (root->left)
		item_find = ft_bstchr(root->left, data_ref, cmpf);
	if (!item_find && (*cmpf)(data_ref, root->content) == 0)
		return (root);
	if (!item_find && root->right)
		item_find = ft_bstchr(root->right, data_ref, cmpf);
	return (item_find);
}
