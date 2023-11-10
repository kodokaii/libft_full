/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/10 20:47:20 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	**current;
	void	*content;

	root = NULL;
	current = &root;
	while (lst)
	{
		content = (*f)(lst->content);
		*current = ft_lstnew(content);
		if (!*current)
		{
			ft_lstclear(&root, del);
			if (del)
				(*del)(content);
			return (NULL);
		}
		current = &(*current)->next;
		lst = lst->next;
	}
	return (root);
}
