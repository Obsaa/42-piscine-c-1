/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:33:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/15 10:33:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		*ft_map(int *tab, int length, int(*f)(int));

int		times_two(int n)
{
	return(2 * n);
}

int		main(void)
{
	int		tab[4] = {14, 27, 42, 12};
	int		*output;
	int		i;

	for (i = 0; i < 4; i++)
		printf("%i\n", tab[i]);
	output = ft_map(tab, 4, &times_two);
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%i\n", tab[i]);
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%i\n", output[i]);
	return (1);
}
