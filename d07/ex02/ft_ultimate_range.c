/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:32:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 20:58:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	tab = (int*)malloc(sizeof(int) * (max - min + 1));
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	tab[i] = 0;
	*range = tab;
	return (i);
}
