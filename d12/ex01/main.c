/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:55:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/22 10:58:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define BUF_SIZE 10

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("File name mising.");
		return (1);
	}
	return (0);
}

void	ft_bad_name(char *str)
{
	ft_putstr("cat: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ft_error(ac))
		return (1);
	av++;
	while (*av)
	{
		fd = open(*av, O_RDONLY);
		if (fd == -1)
			ft_bad_name(*av);
		else
			while ((ret = read(fd, buf, BUF_SIZE)))
			{
				buf[ret] = '\0';
				write(1, buf, ret);
			}
		close(fd);
		av++;
	}
	return (errno);
}
