/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 12:16:26 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/12 16:26:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define USAGE_MSG "error : only [ + - * / % ] are accepted.\n"

void	ft_putstr(char *str);

int		ft_usage(int a, int b)
{
	a = 0;
	b = 0;
	ft_putstr(USAGE_MSG);
	return (0);
}
