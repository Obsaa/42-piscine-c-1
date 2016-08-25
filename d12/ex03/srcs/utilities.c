/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 11:38:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/22 22:04:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_bad_name(char *str)
{
	ft_putstr("hexdump: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

void	ft_bad_fd(char *str)
{
	ft_putstr("hexdump: ");
	ft_putstr(str);
	ft_putstr(": Bad file descriptor\n");
}
