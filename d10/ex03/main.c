/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:33:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/15 10:33:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_any(char **tab, int(*f)(char*));

int		equals_4(char* str)
{
	if (str[0] == '4' && str[1] == '\0')
		return (1);
	return (0);
}

int		main(void)
{
	char	*(tab[4]) = {"facebook", "42", "0google", "0"};
	printf("%i\n", equals_4(tab[1]));
	printf("%i\n", ft_any(tab, &equals_4));
	return (0);
}
