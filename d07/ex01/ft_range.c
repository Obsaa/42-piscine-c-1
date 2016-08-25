/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:32:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 10:21:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*table;

	if (min >= max)
		return (0);
	table = (int*)malloc(sizeof(*table) * (max - min + 1));
	i = 0;
	while (min + i < max)
	{
		table[i] = min + i;
		i++;
	}
	table[i] = 0;
	return (table);
}
