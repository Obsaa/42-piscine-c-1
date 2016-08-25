/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:33:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 10:29:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		size_calc(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		size;
	int		i;
	int		j;
	int		k;
	char	*concat;

	i = 1;
	j = 0;
	k = 0;
	size = size_calc(argc, argv) + argc;
	concat = (char*)malloc(sizeof(char *) * (size + 1));
	while (i < argc)
	{
		while (argv[i][j])
			concat[k++] = argv[i][j++];
		i++;
		j = 0;
		if (i < argc)
			concat[k++] = '\n';
	}
	concat[k] = '\0';
	return (concat);
}
