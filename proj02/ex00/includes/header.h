/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 12:02:50 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 18:17:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	int	(*t_function)(int, int);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_itoa(int nbr);
char			*ft_strcat(char *dest, char *src);
char			*ft_strdup(char *src);

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);

int				ft_do_op(char *str);
int				eval_expr(char *str);

typedef struct	s_opp
{
	char		c;
	t_function	func;
}				t_opp;
t_opp g_optab0[] =
{
	{'+', &ft_add},
	{'\0', &ft_add},
};
t_opp g_optab1[] =
{
	{'*', &ft_mul},
	{'/', &ft_div},
	{'%', &ft_mod},
	{'\0', &ft_add},
};
t_opp *(g_optab[]) = {g_optab0, g_optab1};

#endif
