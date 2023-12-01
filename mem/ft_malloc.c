/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/12/01 01:46:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	_new_alloc(t_alloc *alloc)
{
	void	*ptr;
	t_list	*new_current;

	ptr = malloc(BUFFER_SIZE);
	if (!ptr)
		return (EXIT_FAILURE);
	new_current = ft_lstnew(ptr);
	if (!new_current)
	{
		free(ptr);
		return (EXIT_FAILURE);
	}
	ft_lstadd_back(&alloc->memory, new_current);
	alloc->current = new_current;
	alloc->free_size = BUFFER_SIZE;
	return (EXIT_SUCCESS);
}

void	ft_reset(t_alloc *alloc)
{
	if (alloc->memory)
	{
		alloc->current = alloc->memory;
		alloc->free_size = BUFFER_SIZE;
	}
}

void	ft_free(t_alloc *alloc)
{
	ft_lstclear(&alloc->memory, free);
	alloc->current = NULL;
	alloc->free_size = 0;
}

void	*ft_malloc(t_alloc *alloc, size_t size)
{
	void	*ptr;

	if (BUFFER_SIZE < size)
		return (NULL);
	if (alloc->free_size < size)
	{
		if (alloc->current && alloc->current->next)
		{
			alloc->current = alloc->current->next;
			alloc->free_size = BUFFER_SIZE;
		}
		else if (_new_alloc(alloc))
			return (NULL);
	}
	ptr = ((t_byte *)alloc->current->data) + BUFFER_SIZE - alloc->free_size;
	alloc->free_size -= size;
	return (ptr);
}
