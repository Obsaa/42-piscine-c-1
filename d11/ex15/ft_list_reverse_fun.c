/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:20:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/18 18:43:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_list_size2(t_list *begin_list)
{
	t_list	*list;
	int		count;

	list = begin_list;
	count = 0;
	if (list)
	{
		count = 1;
		while (list->next)
		{
			list = list->next;
			count++;
		}
	}
	return (count);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*a;
	t_list	*b;
	int		cur;
	int		i;
	void	*tmp;

	a = begin_list;
	b = NULL;
	cur = ft_list_size2(begin_list);
	while (a != b)
	{
		b = begin_list;
		i = 1;
		while (i++ < cur)
			b = b->next;
		if (a == b)
			break ;
		tmp = a->data;
		a->data = b->data;
		b->data = tmp;
		a = a->next ? a->next : a;
		cur--;
	}
	a = begin_list;
}
