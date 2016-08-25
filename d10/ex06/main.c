/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:09:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/17 22:41:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_err(char opp, int b)
{
	if (b == 0)
	{
		if (opp == '/')
		{
			ft_putstr("Stop : division by zero\n");
			return (1);
		}
		else if (opp == '%')
		{
			ft_putstr("Stop : modulo by zero\n");
			return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int			i;
	char		*op;

	op = "+-*/%\0";
	if (ac != 4)
		return (0);
	if (ft_err(av[2][0], ft_atoi(av[3])))
		return (0);
	i = 0;
	while (op[i])
	{
		if (op[i] == av[2][0])
		{
			ft_putnbr(g_opps[i](ft_atoi(av[1]), ft_atoi(av[3])));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
