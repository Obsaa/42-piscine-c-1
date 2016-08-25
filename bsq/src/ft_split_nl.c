/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:03:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/23 12:53:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SEP(x) (x=='\n')

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
	table = (char**)malloc(sizeof(*table) * (n_words + 10));
	table[n_words] = 0;
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
		if (SEP(str[i]) || !str[i])
		{
			table[j] = (char*)malloc(sizeof(**table) * (k + 10));
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
		if (SEP(str[i]) || !str[i])
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

char	**ft_split_nl(char *str)
{
	char	**table;

	table = 0;
	table = alloc_table(table, str);
	table = alloc_words(table, str);
	table = fill_table(table, str);
	return (table);
}
