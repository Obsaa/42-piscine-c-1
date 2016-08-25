/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:37:16 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 11:19:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_sort_wordtab(char **tab);
char	**ft_split_whitespaces(char *str);

int		main(int ac, char **av)
{ 
	char	**tab;
	int		i = 0;

	tab = ft_split_whitespaces(av[1]);
	ft_sort_wordtab(tab);
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
	return (0);
}
