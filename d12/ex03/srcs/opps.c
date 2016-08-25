/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:37:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/22 22:04:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	size;
	int	cmp;
	int i;

	size = 1;
	i = 0;
	cmp = 0;
	while (1)
	{
		cmp += (s1[i] - s2[i]);
		if (i >= (int)n - 1)
			return (cmp);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (cmp);
		if (s1[i] == s2[i])
			i++;
		else
			return (cmp);
	}
}

void	ft_putnbr_base16(int nbr, int format)
{
	int		base_size;
	int		i;
	int		result[100];

	base_size = 16;
	i = 0;
	if (base_size > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		while (nbr)
		{
			result[i] = nbr % base_size;
			nbr = nbr / base_size;
			i++;
		}
		while (format-- > i)
			ft_putchar('0');
		while (--i >= 0)
			ft_putchar("0123456789abcdef"[result[i]]);
	}
}
