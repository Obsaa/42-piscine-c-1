/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:58:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/09 16:11:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) (((x) < 0) ? -(x) : (x))

void	ft_putchar(char c);

int		get_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if (str[i] < 32 || str[i] > 126)
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	int		i;
	int		result[100];

	base_size = get_size(base);
	i = 0;
	if (base_size > 1)
	{
		if (nbr < 0)
			ft_putchar('-');
		while (nbr)
		{
			result[i] = ABS(nbr % base_size);
			nbr = nbr / base_size;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[result[i]]);
	}
}
