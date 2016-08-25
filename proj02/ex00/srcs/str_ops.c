/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:21:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 18:23:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define NEG(x) (((x) < 0) ? 1 : 0)
#define ABS(x) (((x) < 0) ? -(x) : x)

char	*ft_strrev(char *str)
{
	int		len;
	char	tmp;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		tmp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

int		ft_atoi(char *str)
{
	int	i;
	int	res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			sign = (str[i] == '+') ? 1 : -1;
			i++;
		}
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + sign * (str[i++] - '0');
	return (res);
}

char	*ft_itoa(int num)
{
	int		i;
	int		neg;
	char	*str;

	i = 0;
	str = (char *)malloc(10000);
	neg = 0;
	if (num < 0)
		neg = 1;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num)
	{
		str[i++] = ABS(num % 10) + '0';
		num = num / 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
