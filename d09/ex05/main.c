/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:09:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 10:13:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_bouton(int i, int j, int k);

int		main(void)
{
	printf("%i\n",ft_bouton(1,2,3));
	printf("%i\n",ft_bouton(2,2,2));
	printf("%i\n",ft_bouton(2,3,1));
	printf("%i\n",ft_bouton(1,2,2));
	printf("%i\n",ft_bouton(3,2,2));
}
