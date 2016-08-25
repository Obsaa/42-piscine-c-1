/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 22:24:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/11 11:33:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_par *par);

int					main(int ac, char **av)
{
	t_stock_par	*par;

	par = ft_param_to_tab(ac, av);
	ft_show_tab(par);
}
