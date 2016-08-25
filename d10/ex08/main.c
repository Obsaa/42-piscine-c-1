/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:37:16 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 11:23:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
char	**ft_split_whitespaces(char *str);

int		ft_strcmp(char *s1, char *s2)
{
	int	cmp;
	int i;

	i = 0;
	cmp = 0;
	while (1 == 1)
	{
		cmp += (s1[i] - s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (cmp);
		if (s1[i] == s2[i])
			i++;
		else
			return (cmp);
	}
}

int		main(int ac, char **av)
{ 
	char	**tab;
	int		i = 0;

	tab = ft_split_whitespaces(av[1]);
	ft_advanced_sort_wordtab(tab, &ft_strcmp);
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
	return (0);
}
