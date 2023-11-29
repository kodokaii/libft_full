/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/29 15:59:35 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstsort_merge(t_list **root, t_list *list, int (*cmp)())
{
	t_list	**current;
	t_list	*buf;

	current = root;
	while (list)
	{
		if (!*current || 0 < cmp((*current)->data, list->data))
		{
			buf = list->next;
			ft_lstadd_front(current, list);
			list = buf;
		}
		current = &(*current)->next;
	}
}
