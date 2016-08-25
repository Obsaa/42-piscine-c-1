/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:33:02 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 23:25:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "string.h"
#include <stdlib.h>
#include "ft_string.h"
#include <fcntl.h>
#define MIN(x,y) (x > y ? y : x)

int		g_dimension[2];

void	foret_de_if(int **tab, int *max, int x, int y)
{
	if (max[2] < tab[y][x])
	{
		max[2] = tab[y][x];
		max[0] = x;
		max[1] = y;
		max[3] = 0;
	}
	if (x + 1 != g_dimension[1] && y + 1 != g_dimension[0]
			&& max[2] == tab[y][x]
			&& max[2] == tab[y + 1][x + 1] && max[2] == tab[y][x + 1]
			&& max[2] == tab[y + 1][x] && max[3] != 1)
	{
		max[0] = x;
		max[1] = y;
		max[3] = 1;
	}
}

int		*print_rez(int **tab)
{
	int *max;
	int x;
	int y;

	max = malloc(sizeof(int) * 4);
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	max[3] = 0;
	y = 0;
	while (y < g_dimension[0])
	{
		x = 0;
		while (x < g_dimension[1])
		{
			foret_de_if(tab, max, x, y);
			x++;
		}
		y++;
	}
	return (max);
}

void	sinon(int **tab, char block[], int fd[], char **argv)
{
	fd[1] = 1;
	while (fd[1] < fd[2])
	{
		fd[0] = open(argv[fd[1]], O_RDONLY);
		if (fd[0] == -1)
			write(2, "map error\n", 10);
		if (first_line(block, block + 2, block + 1, fd[0]) == -1)
			write(2, "map error\n", 10);
		else
		{
			tab = NULL;
			if (g_dimension[0])
				tab = handle_buffer(block, fd[0]);
			if (tab == NULL)
				write(2, "map error", 9);
			else
				print_result(tab, print_rez(tab), block);
			close(fd[0]);
			write(1, "\n", 1);
		}
		fd[1]++;
	}
}

int		main(int argc, char **argv)
{
	char	block[3];
	int		**tab;
	int		fd[3];

	fd[2] = argc;
	tab = NULL;
	if (argc == 1)
	{
		if (first_line(block, block + 2, block + 1, 0) == -1)
		{
			write(2, "map error\n", 10);
			return (0);
		}
		tab = handle_buffer(block, 0);
		if (tab == NULL)
			write(2, "map error\n", 10);
		else
			print_result(tab, print_rez(tab), block);
	}
	else
		sinon (tab, block, fd, argv);
	return (0);
}

int		**make_tab(void)
{
	int a;
	int **tab;
	int x;
	int y;

	y = g_dimension[0];
	x = g_dimension[1];
	a = 0;
	tab = malloc(sizeof(int*) * y);
	while (a < y)
	{
		tab[a] = malloc(sizeof(int) * x);
		a++;
	}
	a = 0;
	while (a != MIN((x + 1) / 2, (y + 1) / 2))
	{
		make_cadre(tab, a, x, y);
		a++;
	}
	return (tab);
}
