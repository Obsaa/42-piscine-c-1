/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elacaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:20:18 by elacaill          #+#    #+#             */
/*   Updated: 2016/08/25 11:21:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_read_std(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	long	size_str;
	char	*temp;
	char	*res;

	size_str = 0;
	if (fd == -1)
		return ("0\n0");
	res = (char *)malloc(42);
	*res = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		temp = ft_strdup(res);
		free(res);
		size_str += ret;
		res = (char*)malloc(sizeof(char) * (size_str + 1));
		*res = '\0';
		buf[ret] = '\0';
		ft_strcat(res, temp);
		ft_strcat(res, buf);
		free(temp);
	}
	close(fd);
	return (res);
}

char	***ft_fill_grid(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	char	***grid_ptr;

	grid_ptr = (char***)malloc(sizeof(char**) * (ac + 1));
	i = 1;
	if (ac == 1)
	{
		str = ft_read_std(0);
		*grid_ptr = ft_split_nl(str);
		if (str)
			free(str);
		grid_ptr[1] = NULL;
	}
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		str = ft_read_std(fd);
		grid_ptr[i - 1] = ft_split_nl(str);
		grid_ptr[i] = NULL;
		i++;
	}
	return (grid_ptr);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	***grid_ptr;

	grid_ptr = ft_fill_grid(ac, av);
	i = 0;
	while (grid_ptr[i])
	{
		if (ft_bsq(grid_ptr[i]))
			ft_putstr("map error\n");
		j = 0;
		while (grid_ptr[i][j])
			free(grid_ptr[i][j++]);
		free(grid_ptr[i]);
		i++;
		if (ac > 2 && grid_ptr[i])
			ft_putchar('\n');
	}
	free(grid_ptr);
	return (0);
}
