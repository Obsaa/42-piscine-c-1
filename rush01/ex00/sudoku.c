/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 11:28:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/14 21:30:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		ft_is_valid(char **grid, char number, int line, int col)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (grid[i][col] == number)
			return (0);
		if (grid[line][i] == number)
			return (0);
		i++;
	}
	if (grid[CELL_MOINS_UN(line)][CELL_MOINS_UN(col)] == number
		|| grid[CELL_MOINS_UN(line)][CELL_PLUS_UN(col)] == number
		|| grid[CELL_PLUS_UN(line)][CELL_MOINS_UN(col)] == number
		|| grid[CELL_PLUS_UN(line)][CELL_PLUS_UN(col)] == number)
		return (0);
	return (1);
}

int		ft_goto_next(char ***grid_ptr, int line, int col)
{
	if (col == 8)
		return (ft_solver(grid_ptr, line + 1, 0));
	else
		return (ft_solver(grid_ptr, line, col + 1));
}

int		ft_puzzle_solved(void)
{
	if (g_count == -1)
		return (1);
	g_count++;
	if (g_count > 1)
		return (1);
	return (0);
}

int		ft_solver(char ***grid_ptr, int line, int col)
{
	char	**grid;
	char	next;

	grid = *grid_ptr;
	next = '1';
	if (line == 9)
		return (ft_puzzle_solved());
	else if (grid[line][col] >= '1' && grid[line][col] <= '9')
		return (ft_goto_next(grid_ptr, line, col));
	else if (grid[line][col] == '.')
		while (next <= '9')
		{
			if (ft_is_valid(grid, next, line, col))
			{
				grid[line][col] = next;
				if (ft_goto_next(grid_ptr, line, col))
					return (1);
				grid[line][col] = '.';
			}
			next++;
		}
	return (0);
}
