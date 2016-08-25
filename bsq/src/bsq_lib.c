/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:50:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/25 00:06:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			*ft_dimension(char **grid, char a1, char a2)
{
	int		*dim;
	int		i;

	dim = (int *)malloc(sizeof(int) * 2);
	dim[0] = 0;
	dim[1] = 0;
	while (grid[dim[1]])
	{
		i = 0;
		while (grid[dim[1]][i])
		{
			if (grid[dim[1]][i] != a1 && grid[dim[1]][i] != a2)
				return (NULL);
			i++;
		}
		if (dim[1] == 0)
			dim[0] = i;
		if (i != dim[0])
			return (NULL);
		dim[1]++;
	}
	return (dim);
}

int			ft_update(int is_vide, int *i, int *a[2], t_square *sol)
{
	int	out;

	if (i[0] == 0 || i[1] == 0)
		out = (is_vide) ? 1 : 0;
	else
		out = (is_vide) ?
			(1 + min(a[1][i[1] - 1], a[0][i[1] - 1], a[0][i[1]])) : 0;
	if (out > sol->size)
	{
		sol->x = i[1];
		sol->y = i[0];
		sol->size = out;
	}
	return (out);
}

t_square	ft_solve(char **grid, char vide, int x, int y)
{
	int			*a[2];
	int			i[2];
	t_square	sol;

	sol.size = 0;
	a[0] = (int *)(malloc(sizeof(int) * (x + 1)));
	a[1] = (int *)(malloc(sizeof(int) * (x + 1)));
	i[0] = -1;
	while (++i[0] < y)
	{
		i[1] = -1;
		while (++i[1] < x)
		{
			a[1][i[1]] = ft_update((grid[i[0]][i[1]] == vide), i, a, &sol);
			if (i[1] > 0)
				a[0][i[1] - 1] = a[1][i[1] - 1];
		}
		a[0][i[1] - 1] = a[1][i[1] - 1];
	}
	free(a[0]);
	free(a[1]);
	return (sol);
}

t_data		ft_parse_data(char *str)
{
	t_data	out;
	int		len;

	len = ft_strlen(str);
	out.plein = str[len - 1];
	out.obstacle = str[len - 2];
	out.vide = str[len - 3];
	str[len - 3] = '\0';
	out.size = ft_atoi(str);
	return (out);
}

int			ft_bsq(char **grid)
{
	t_square	sol;
	t_data		data;
	int			*dim;

	data = ft_parse_data(grid[0]);
	grid++;
	if (!(dim = ft_dimension(grid, data.vide, data.obstacle)))
		return (1);
	if (data.size != dim[1])
		return (1);
	sol = ft_solve(grid, data.vide, dim[0], dim[1]);
	ft_print_sol(grid, sol, data.plein);
	free(dim);
	return (0);
}
