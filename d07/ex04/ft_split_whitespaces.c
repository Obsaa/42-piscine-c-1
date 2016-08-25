/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:33:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/20 23:23:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define SEP(x) (x==' ' || x=='\n' || x=='\t')

char	**alloc_table(char **table, char *str)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (SEP(str[i]))
		{
			n_words++;
			while (SEP(str[i]))
				i++;
		}
	}
	if (!SEP(str[i - 1]))
		n_words++;
	table = (char**)malloc(sizeof(*table) * (n_words + 1));
	table[n_words] = 0x0;
	return (table);
}

char	**alloc_words(char **table, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (SEP(str[i]) || str[i] == '\0')
		{
			table[j] = (char*)malloc(sizeof(**table) * (k + 1));
			j++;
			k = 0;
			while (SEP(str[i]))
				i++;
		}
		k++;
	}
	return (table);
}

char	**fill_table(char **table, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		table[j][k] = str[i];
		i++;
		k++;
		if (SEP(str[i]))
		{
			table[j][k] = '\0';
			j++;
			k = 0;
			while (SEP(str[i]))
				i++;
		}
	}
	return (table);
}

char	**ft_split_whitespaces(char *str)
{
	char	**table;

	table = NULL;
	table = alloc_table(table, str);
	table = alloc_words(table, str);
	table = fill_table(table, str);
	return (table);
}
