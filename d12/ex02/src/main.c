/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:54:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/25 17:05:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_badname(char *avi)
{
	int fd;

	fd = open(avi, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("tail: ");
		ft_putstr(avi);
		ft_putstr(": No such file or directory\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	ft_put_filename(int ac, char *avi, int *cpt)
{
	if (*cpt != 0)
		ft_putstr("\n");
	if (ac > 4)
	{
		ft_putstr("==> ");
		ft_putstr(avi);
		ft_putstr(" <==\n");
	}
}

void	ft_tail(int ac, char *avi, int size, int *cpt)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*buf_temp;
	int		size_file;

	if (ft_check_badname(avi))
	{
		size_file = ft_get_size(avi);
		fd = open(avi, O_RDONLY);
		if (size < size_file)
		{
			buf_temp = (char*)malloc(sizeof(char) * (size_file - size + 1));
			read(fd, buf_temp, size_file - size);
			free(buf_temp);
		}
		ft_put_filename(ac, avi, cpt);
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		(*cpt)++;
	}
}

int		main(int ac, char **av)
{
	int i;
	int cpt;

	i = 3;
	cpt = 0;
	if (ac > 2)
	{
		if (ft_strcmp(av[1], "-c") == 0)
		{
			if (ft_atoi(av[2]) > 0)
			{
				while (i < ac)
				{
					ft_tail(ac, av[i], ft_atoi(av[2]), &cpt);
					i++;
				}
			}
		}
	}
	return (errno);
}
