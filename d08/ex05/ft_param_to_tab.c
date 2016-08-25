/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:58:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/14 18:52:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>
#include <stdio.h>

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	dup = (char*)malloc(sizeof(*dup) * (size + 1));
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*first_struc;
	t_stock_par	*struc;

	first_struc = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 2));
	struc = first_struc;
	i = 0;
	while (i < ac)
	{
		struc->copy = ft_strdup(av[i]);
		struc->str = av[i];
		struc->tab = ft_split_whitespaces(av[i]);
		struc->size_param = ft_strlen(av[i]);
		struc++;
		i++;
	}
	struc->str = 0;
	return (first_struc);
}
