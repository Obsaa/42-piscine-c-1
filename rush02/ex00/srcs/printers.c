/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:31:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 20:54:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_put_bracket(int nb)
{
	ft_putstr("[colle-0");
	ft_putchar(nb);
	ft_putstr("]");
}

void	ft_put_dimensions(int x, int y)
{
	ft_putstr(" [");
	ft_putchar(x + '0');
	ft_putstr("] [");
	ft_putchar(y + '0');
	ft_putstr("]");
}

void	ft_print_solution(char *colles, int *dim)
{
	int		i;

	ft_put_bracket(colles[0]);
	ft_put_dimensions(dim[0], dim[1]);
	i = 1;
	while (colles[i])
	{
		ft_putstr(" || ");
		ft_put_bracket(colles[i++]);
		ft_put_dimensions(dim[0], dim[1]);
	}
	ft_putchar('\n');
}
