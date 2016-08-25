/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:17:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/16 22:00:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*next_link;
	t_list	*link;

	link = *begin_list;
	while (link)
	{
		next_link = link->next;
		free(link);
		link = next_link;
	}
	*begin_list = NULL;
}
