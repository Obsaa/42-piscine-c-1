/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:53:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/16 22:50:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_swap(t_list **current)
{
	t_list	*tmp;

	tmp = (*current)->next->next;
	(*current)->next->next = (*current);
	(*current)->next = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*last;

	current = *begin_list;
	if (!*begin_list)
		return ;
	while (current->next)
	{
		if ((*cmp)(current->data, current->next->data) > 0)
		{
			if (current != *begin_list)
				last->next = current->next;
			else
				*begin_list = current->next;
			ft_list_swap(&current);
			current = *begin_list;
		}
		else
		{
			last = current;
			current = current->next ? current->next : current;
		}
	}
}
