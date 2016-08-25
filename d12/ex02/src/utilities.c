/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:56:07 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/25 17:25:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	cmp;
	int i;

	i = 0;
	cmp = 0;
	while (1)
	{
		cmp += (s1[i] - s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (cmp);
		if (s1[i] == s2[i])
			i++;
		else
			return (cmp);
	}
}

int		ft_get_size(char *filename)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		size_file;

	size_file = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		size_file += ret;
	}
	close(fd);
	return (size_file);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
