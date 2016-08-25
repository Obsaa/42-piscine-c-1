/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:22:34 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/22 10:51:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include <stdlib.h>
#include <stdio.h>

int		*ft_dimension(char **split)
{
	int		*dim;
	int		column;

	dim = (int *)malloc(sizeof(int) * 2);
	dim[0] = 0;
	dim[1] = 0;
	column = 0;
	while (split[dim[1]])
	{
		column = 0;
		while (split[dim[1]][column])
			column++;
		if (dim[1] == 0)
			dim[0] = column;
		if (column != dim[0])
			return (NULL);
		dim[1]++;
	}
	return (dim);
}

char	*ft_makeline(t_pattern pat, int size)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (size + 1));
	i = 1;
	line[size] = '\0';
	while (i < size)
		line[i++] = pat.b;
	line[size - 1] = pat.c;
	line[0] = pat.a;
	return (line);
}
