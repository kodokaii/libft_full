/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/30 23:07:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew_alloc(t_alloc *alloc, void *data)
{
	t_list	*new;

	new = ft_malloc(alloc, sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}
