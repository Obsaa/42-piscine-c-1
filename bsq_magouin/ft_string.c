/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 08:48:55 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 20:45:22 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_malloc_zero(int nb)
{
	char	*s;
	int		i;

	s = malloc(nb * sizeof(char));
	if (s == NULL)
		return (0);
	i = 0;
	while (i < nb - 1)
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*rez;

	rez = ft_malloc_zero(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		rez[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		rez[i] = s2[j];
		j++;
		i++;
	}
	rez[i] = '\0';
	return (rez);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
