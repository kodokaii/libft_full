/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstlevel_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:58:26 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:58:52 by nlaerema         ###   ########.fr       */
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
