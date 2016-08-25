/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 19:16:21 by magouin           #+#    #+#             */
/*   Updated: 2015/07/30 21:17:03 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	make_cadre(int **tab, int target, int longeur, int hauteur)
{
	int a;
	int b;

	a = target;
	b = target;
	while (a < longeur - target)
	{
		tab[b][a] = target + 1;
		a++;
	}
	a--;
	while (b < hauteur - target)
	{
		tab[b][a] = target + 1;
		b++;
	}
	b--;
	while (--a >= target)
		tab[b][a] = target + 1;
	a++;
	while (--b >= target)
		tab[b][a] = target + 1;
}

void	affiche(int **tab, char *block)
{
	int x;
	int y;

	y = 0;
	while (y < g_dimension[0])
	{
		x = 0;
		while (x < g_dimension[1])
		{
			if (tab[y][x] == 0)
				write(1, block + 2, 1);
			else if (tab[y][x] == -1)
				write(1, block + 1, 1);
			else
				write(1, block, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	print_result(int **tab, int *max, char *block)
{
	int x;
	int y;

	max[2]--;
	y = max[1] - max[2];
	while (y <= max[1] + max[2] + max[3])
	{
		x = max[0] - max[2];
		while (x <= max[0] + max[2] + max[3])
		{
			tab[y][x] = -1;
			x++;
		}
		y++;
	}
	affiche(tab, block);
}

void	percolation(int **tab, int x, int y)
{
	tab[y][x] = 0;
	if (x != 0)
	{
		tab[y][x] = 1;
		recursifg(tab, x, y, 0);
	}
	if (x != g_dimension[1] - 1)
	{
		tab[y][x] = 1;
		recursifd(tab, x, y, 0);
	}
	if (y != 0)
	{
		tab[y][x] = 1;
		recursifh(tab, x, y, 0);
	}
	if (y != g_dimension[0] - 1)
	{
		tab[y][x] = 1;
		recursifb(tab, x, y, 0);
	}
}
