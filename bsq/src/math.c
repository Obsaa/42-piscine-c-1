/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:15:57 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/24 17:37:47 by elacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

int		ft_atoi(char *str)
{
	int		if_negativ;
	int		count;
	int		num;

	if_negativ = 0;
	count = 0;
	num = 0;
	while (str[0] == ' ')
		str++;
	if (str[0] == '-')
		if_negativ = 1;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while ((str[count] >= '0' && str[count] <= '9'))
	{
		num += str[count] - 48;
		if (str[count + 1] >= '0' && str[count + 1] <= '9')
			num *= 10;
		count++;
	}
	if (if_negativ == 1)
		return (-num);
	return (num);
}
