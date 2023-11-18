/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/15 21:39:21 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bstiter_prefix(t_bst *root, void (*f)())
{
	f(root->data);
	if (root->left)
		ft_bstiter_prefix(root->left, f);
	if (root->right)
		ft_bstiter_prefix(root->right, f);
}
