/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:30:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 15:29:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>

typedef	int	(*t_function)(int, int);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int			ft_add(int a, int b);
int			ft_sub(int a, int b);
int			ft_mul(int a, int b);
int			ft_div(int a, int b);
int			ft_mod(int a, int b);
int			ft_atoi(char *str);
t_function	g_opps[] = { ft_add, ft_sub, ft_mul, ft_div, ft_mod };
#endif
