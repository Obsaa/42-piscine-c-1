/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 23:16:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 16:55:10 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	cmp;
	int i;

	i = 0;
	cmp = 0;
	while (1)
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
