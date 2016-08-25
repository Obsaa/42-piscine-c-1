/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 20:03:37 by magouin           #+#    #+#             */
/*   Updated: 2015/07/30 21:15:55 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void recursifg(int **tab, int x, int y, int value)
{
	if (tab[y][x] > value)
	{
		tab[y][x] = value;
		if (x != 0 && y != g_dimension[0] - 1)
			recursifg(tab, x - 1, y + 1, value + 1);
		if (x != 0)
			recursifg(tab, x - 1, y, value + 1);
		if (x != 0 && y != 0)
			recursifg(tab, x - 1, y - 1, value + 1);
	}
}

void recursifd(int **tab, int x, int y, int value)
{
	if (tab[y][x] > value)
	{
		tab[y][x] = value;
		if (x != g_dimension[1] - 1 && y != g_dimension[0] - 1)
			recursifd(tab, x + 1, y + 1, value + 1);
		if (x != g_dimension[1] - 1)
			recursifd(tab, x + 1, y, value + 1);
		if (x != g_dimension[1] - 1 && y != 0)
			recursifd(tab, x + 1, y - 1, value + 1);
	}
}

void recursifh(int **tab, int x, int y, int value)
{
	if (tab[y][x] > value)
	{
		tab[y][x] = value;
		if (x != g_dimension[1] - 1 && y != 0)
			recursifh(tab, x + 1, y - 1, value + 1);
		if (y != 0)
			recursifh(tab, x, y - 1, value + 1);
		if (x != 0 && y != 0)
			recursifh(tab, x - 1, y - 1, value + 1);
	}
}

void recursifb(int **tab, int x, int y, int value)
{
	if (tab[y][x] > value)
	{
		tab[y][x] = value;
		if (x != g_dimension[1] - 1 && y != g_dimension[0] - 1)
			recursifb(tab, x + 1, y + 1, value + 1);
		if (y != g_dimension[0] - 1)
			recursifb(tab, x, y + 1, value + 1);
		if (x != 0 && y != g_dimension[0] - 1)
			recursifb(tab, x - 1, y + 1, value + 1);
	}
}
