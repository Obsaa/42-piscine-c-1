/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:11:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/14 18:33:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		count_words(char *str);
char	**ft_split_whitespaces(char *str);

int		main(void)
{
	/* char	*phrase = " \t  m\ny name is\t hello\n\t  world\t \n"; */
	char	*phrase = "./a.out abcdefg 123";
	char	**table = ft_split_whitespaces(phrase);

	printf("%s\n", phrase);
	while (*table)
		printf("%s\n", *table++);
	return (0);
}
