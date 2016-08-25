/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 14:37:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/14 21:42:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		g_count = 0;

int		ft_find_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 10)
		return (1);
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j])
			j++;
		if (j != 9)
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	av++;
	if (ft_find_error(ac, av))
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	ft_solver(&av, 0, 0);
	if (g_count != 1)
		ft_putstr("Erreur\n");
	else
	{
		g_count = -1;
		ft_solver(&av, 0, 0);
		ft_print_sudoku(av);
	}
	return (0);
}
