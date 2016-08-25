/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 21:03:43 by fchanal           #+#    #+#             */
/*   Updated: 2016/08/21 20:55:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_get_stdin(void)
{
	int		ret;
	int		total_size;
	char	buf[BUF_SIZE + 1];
	char	*final;
	char	tmp[100000];

	total_size = 0;
	final = malloc(42);
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		ft_strcpy(tmp, final);
		free(final);
		buf[ret] = '\0';
		total_size += ret;
		final = (char *)malloc(sizeof(char) * total_size);
		final = ft_strcat(tmp, buf);
	}
	return (final);
}

char	*ft_test_patterns(char **tab, int x, int y)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	res = (char *)malloc(sizeof(char) * 5);
	i = -1;
	k = 0;
	while (g_p[++i][0].a)
	{
		if (ft_strcmp(tab[0], ft_makeline(g_p[i][0], x)) != 0)
			continue ;
		if (y > 1 && ft_strcmp(tab[y - 1], ft_makeline(g_p[i][2], x)) != 0)
			continue ;
		j = 1;
		while (y > 2 && j < y - 1)
			if (ft_strcmp(tab[j++], ft_makeline(g_p[i][1], x)) != 0)
				break ;
		if (y > 2 && j != y - 1)
			continue ;
		res[k++] = i + '0';
	}
	res[k] = '\0';
	return (res);
}

int		main(void)
{
	char	*input;
	int		*dim;
	char	*colles;
	char	**tab;

	input = ft_get_stdin();
	tab = ft_split_nl(input);
	if (!(dim = ft_dimension(tab)))
	{
		ft_putstr("aucune\n");
		return (0);
	}
	colles = ft_test_patterns(tab, dim[0], dim[1]);
	if (colles[0] == '\0')
	{
		ft_putstr("aucune\n");
		return (0);
	}
	ft_print_solution(colles, dim);
}
