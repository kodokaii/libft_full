/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstlevel_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:57:53 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/13 02:11:31 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_bstlevel_count(t_bst *root)
{
	int	sz_left;
	int	sz_right;

	sz_left = 0;
	sz_right = 0;
	if (root->left)
		sz_left = ft_bstlevel_count(root->left) + 1;
	if (root->right)
		sz_right = ft_bstlevel_count(root->right) + 1;
	if (sz_left < sz_right)
		return (sz_right);
	return (sz_left);
}
