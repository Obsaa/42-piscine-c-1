/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:55:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/22 11:24:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_error(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("Not enough args.\n");
		return (1);
	}
	if (ft_strncmp(av[1], "-C", 3) == 0 && ac == 2)
	{
		ft_putstr("Not enough args.\n");
		return (1);
	}
	return (0);
}

unsigned int	ft_make_data(char **av, void **addr)
{
	int				fd;
	int				ret;
	unsigned int	total_size;
	char			buf[BUF_SIZE + 1];

	total_size = 0;
	*addr = (char *)malloc(sizeof(char) * 10000);
	while (*av)
	{
		fd = open(*av, O_RDONLY);
		if (fd == -1)
			ft_bad_name(*av);
		else
			while ((ret = read(fd, buf, BUF_SIZE)))
			{
				total_size += ret;
				buf[ret] = '\0';
				ft_strcat(*addr, buf);
			}
		av++;
	}
	return (total_size);
}

int				main(int ac, char **av)
{
	int				option;
	void			*addr;
	unsigned int	total_size;

	if (ft_error(ac, av))
		return (1);
	option = (ft_strncmp(av[1], "-C", 3) == 0);
	total_size = ft_make_data(av + 1 + option, &addr);
	if (total_size)
		ft_hexdump(addr, total_size, option);
	else
		ft_bad_fd(av[ac - 1]);
	return (errno);
}
