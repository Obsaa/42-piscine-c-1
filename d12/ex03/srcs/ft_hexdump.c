/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:26:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/19 22:57:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_contents(void *addr, unsigned int size)
{
	void	*a;

	a = addr;
	ft_putstr("  |");
	while (a - addr < 16)
	{
		if ((a - addr) >= size)
			break ;
		else if (*(char *)a < 32 || *(char *)a > 126)
			ft_putchar('.');
		else
			ft_putchar(*(char *)a);
		a++;
	}
	ft_putchar('|');
}

void	ft_print_hex_contents(void *addr, unsigned int size, int option)
{
	void	*a;

	a = addr;
	(void)option;
	while (a - addr < 16)
	{
		ft_putchar(' ');
		if (option && IS_DIV((a - addr), 8))
			ft_putchar(' ');
		if ((a - addr) >= size)
			ft_putstr("  ");
		else
			ft_putnbr_base16(*(char *)a, 2);
		a++;
	}
}

void	*ft_hexdump(void *addr, unsigned int size, int option)
{
	void	*a;

	a = addr;
	while ((a - addr) < size)
	{
		ft_putnbr_base16((int)(a - addr), 7 + option);
		ft_print_hex_contents(a, (size - (a - addr)), option);
		if (option)
			ft_print_contents(a, (size - (a - addr)));
		ft_putchar('\n');
		a += 16;
		if (!ft_strncmp((char *)a, (char *)(a - 16), 16))
		{
			ft_putstr("*\n");
			while (!ft_strncmp((char *)a, (char *)(a - 16), 16))
				a += 16;
		}
	}
	if (a != addr)
	{
		ft_putnbr_base16(size, 7 + option);
		ft_putchar('\n');
	}
	return (addr);
}
