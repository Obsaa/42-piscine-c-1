/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 23:08:35 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 10:46:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_print_param(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
	ft_putchar('\n');
}

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

void	ft_sort_params(char **list, int size)
{
	int		sorted;
	int		i;
	char	*tmp;

	i = 0;
	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < size - 1)
		{
			if (ft_strcmp(list[i], list[i + 1]) > 0)
			{
				sorted = 0;
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_params(argv + 1, argc - 1);
	while (i < argc)
	{
		ft_print_param(argv[i]);
		i++;
	}
	return (0);
}
