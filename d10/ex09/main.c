/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:09:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/15 20:58:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "ft_opp.h"

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

	if (ac != 4)
		return (0);
	if (ft_err(av[2][0], ft_atoi(av[3])))
		return (0);
	i = 0;
	while (i < 5)
	{
		if (*gl_opptab[i].c == av[2][0])
		{
			ft_putnbr((gl_opptab[i].func)(ft_atoi(av[1]), ft_atoi(av[3])));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	(gl_opptab[5].func)(ft_atoi(av[1]), ft_atoi(av[3]));
	return (0);
}
