/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/02 13:29:30 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstdup(t_list *lst_dst, t_list *lst_src)
{
	t_list	**current;
	t_list	*new;

	lst_dst = NULL;
	current = &lst_dst;
	while (lst_src)
	{
		new = ft_lstnew(lst_src->data);
		if (!new)
		{
			ft_lstclear(&lst_dst, NULL);
			return (EXIT_FAILURE);
		}
		ft_lstadd_front(current, new);
		current = &(*current)->next;
		lst_src = lst_src->next;
	}
	return (EXIT_SUCCESS);
}
