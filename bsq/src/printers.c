/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:31:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/24 17:25:52 by elacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_grid(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_sol(char **grid, t_square sol, char x)
{
	int		i;
	int		j;

	i = sol.y;
	while (i >= 0 && i > sol.y - sol.size)
	{
		j = sol.x;
		while (j >= 0 && j > sol.x - sol.size)
		{
			grid[i][j] = x;
			j--;
		}
		i--;
	}
	ft_print_grid(grid);
}
