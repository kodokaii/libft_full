/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:05:07 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bstiter_suffix(t_bst *root, void (*f)(void *))
{
	if (root->left)
		ft_bstiter_suffix(root->left, f);
	if (root->right)
		ft_bstiter_suffix(root->right, f);
	f(root->data);
}
