/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:45:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 20:04:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define AM(hour) ((hour < 12 || hour == 24) ? 1 : 0)

void	print_ampm(int hour)
{
	char	*period;

	period = AM(hour) ? "A.M" : "P.M";
	hour %= 12;
	hour += (hour ? 0 : 12);
	printf("%02d.00 %s", hour, period);
}

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	print_ampm(hour);
	printf(" AND ");
	print_ampm((hour + 1) % 24);
	printf("\n");
}
