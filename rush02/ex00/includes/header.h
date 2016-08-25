/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 20:55:19 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 19:18:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 32

# include "patterns.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char			**ft_split_nl(char *str);
int				*ft_dimension(char **split);
char			*ft_makeline(t_pattern pat, int size);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_put_bracket(int nb);
void			ft_put_dimensions(int x, int y);
void			ft_print_solution(char *colles, int *dim);

int				ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);

t_pattern	g_colle00[] =
{
	{'o', '-', 'o'},
	{'|', ' ', '|'},
	{'o', '-', 'o'},
};
t_pattern	g_colle01[] =
{
	{'/', '*', '\\'},
	{'*', ' ', '*'},
	{'\\', '*', '/'},
};
t_pattern	g_colle02[] =
{
	{'A', 'B', 'A'},
	{'B', ' ', 'B'},
	{'C', 'B', 'C'},
};
t_pattern	g_colle03[] =
{
	{'A', 'B', 'C'},
	{'B', ' ', 'B'},
	{'A', 'B', 'C'},
};
t_pattern	g_colle04[] =
{
	{'A', 'B', 'C'},
	{'B', ' ', 'B'},
	{'C', 'B', 'A'},
};
t_pattern	g_end[] =
{
	{'\0', '\0', '\0'}
};

t_pattern *(g_p[]) = {g_colle00, g_colle01, g_colle02,
	g_colle03, g_colle04, g_end};
#endif
