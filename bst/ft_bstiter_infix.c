/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter_infix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:38 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bstiter_infix(t_bst *root, void (*f)())
{
	if (root->left)
		ft_bstiter_infix(root->left, f);
	f(root->data);
	if (root->right)
		ft_bstiter_infix(root->right, f);
}
