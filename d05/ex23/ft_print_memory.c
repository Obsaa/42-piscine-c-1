/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:03:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/25 13:00:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_size_23(char *str)
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

void	ft_putnbr_base_23(int nbr, char *base, int format)
{
	int		base_size;
	int		i;
	int		result[100];

	base_size = get_size_23(base);
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
			ft_putchar(base[0]);
		while (--i >= 0)
			ft_putchar(base[result[i]]);
	}
}

void	ft_print_contents(int i, void *addr)
{
	void	*a;
	int		j;

	ft_putchar(' ');
	a = addr;
	while (a - addr < 16)
	{
		if (*(char *)a < 32 || *(char *)a > 126)
			ft_putchar('.');
		else
			ft_putchar(*(char *)a);
		a++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*a;

	while ((a - addr) < size || (a - addr) % 16)
	{
		if ((a - addr) % 16 == 0)
		{
			ft_putnbr_base_23((int)(a - addr), "0123456789abcdef", 8);
			ft_putchar(':');
			ft_putchar(' ');
		}
		if ((a - addr) % 2 == 0 && (a - addr) % 16 != 0)
			ft_putchar(' ');
		if ((a - addr) < size)
			ft_putnbr_base_23(*(char *)a++, "0123456789abcdef", 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
			a++;
		}
		if ((a - addr) % 16 == 0)
			ft_print_contents(a - addr, a - 16);
	}
	return (addr);
}
