/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:33:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 10:42:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SEP(x) (x==' ' || x=='\n' || x=='\t')

int		ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	**alloc_table(char **table, char *str, char *charset)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (ft_is_sep(str[i], charset))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (ft_is_sep(str[i], charset))
		{
			n_words++;
			while (ft_is_sep(str[i], charset))
				i++;
		}
	}
	if (!ft_is_sep(str[i - 1], charset))
		n_words++;
	table = (char**)malloc(sizeof(*table) * (n_words + 1));
	table[n_words] = 0x0;
	return (table);
}

char	**alloc_words(char **table, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_is_sep(str[i], charset))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (ft_is_sep(str[i], charset) || str[i] == '\0')
		{
			table[j] = (char*)malloc(sizeof(**table) * (k + 1));
			j++;
			k = 0;
			while (ft_is_sep(str[i], charset))
				i++;
		}
		k++;
	}
	return (table);
}

char	**fill_table(char **table, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_is_sep(str[i], charset))
		i++;
	while (str[i] != '\0')
	{
		table[j][k] = str[i];
		i++;
		k++;
		if (ft_is_sep(str[i], charset))
		{
			table[j][k] = '\0';
			j++;
			k = 0;
			while (ft_is_sep(str[i], charset))
				i++;
		}
	}
	return (table);
}

char	**ft_split(char *str, char *charset)
{
	char	**table;

	table = NULL;
	table = alloc_table(table, str, charset);
	table = alloc_words(table, str, charset);
	table = fill_table(table, str, charset);
	return (table);
}
