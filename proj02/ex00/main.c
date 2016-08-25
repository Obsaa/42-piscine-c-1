/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:09:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/21 18:46:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_do_op(char *str)
{
	int		j;
	int		left;
	int		right;
	int		priority;
	char	*s;

	priority = -1;
	while (++priority <= 1)
	{
		s = str - 1;
		while (*++s)
		{
			j = -1;
			while (g_optab[priority][++j].c)
				if (*s == g_optab[priority][j].c)
				{
					right = eval_expr(s + 2);
					str[s - str - 1] = '\0';
					left = eval_expr(str);
					return ((g_optab[priority][j].func)(left, right));
				}
		}
	}
	return (ft_atoi(str));
}

char	*eval_parenth(char *str)
{
	char	*inside;
	char	*after;
	int		i;
	int		j;
	int		nb_par;

	i = 0;
	while (str[i] != '(' && str[i])
		i++;
	if (!str[i])
		return (str);
	inside = ft_strdup(str + i + 1);
	nb_par = 1;
	j = i;
	while (nb_par && str[j++])
	{
		nb_par += (str[j] == '(') ? 1 : 0;
		nb_par -= (str[j] == ')') ? 1 : 0;
	}
	inside[j - i - 1] = '\0';
	after = ft_strdup(str + j + 1);
	str[i] = '\0';
	inside = ft_itoa(eval_expr(inside));
	return (ft_strcat(ft_strcat(str, inside), after));
}

char	*ft_parse_minus(char *str)
{
	int		i;
	char	*before;
	char	*out;
	char	*buf;

	i = 0;
	out = str;
	while (str[i])
	{
		if (out[i] == '-' && out[i + 1] == ' ')
		{
			buf = ft_strdup(out);
			before = ft_strdup(out);
			before[i] = '\0';
			if (out != str)
				free(out);
			out = malloc(sizeof(char) * (ft_strlen(out) + 2));
			out = ft_strcat(ft_strcat(before, "+ -"), buf + i + 2);
			free(buf);
			free(before);
			i += 2;
		}
		i++;
	}
	return (out);
}

int		eval_expr(char *str)
{
	char	*a;

	str = eval_parenth(str);
	if (*str != '-')
		str = ft_parse_minus(str);
	return (ft_do_op(str));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
