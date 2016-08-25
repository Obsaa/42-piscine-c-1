/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 08:42:27 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 23:27:09 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_io.h"

int		**handle_buffer(char *block, int fd)
{
	char	*s;
	int		i;
	int		r;
	char	buff[BUFF_SIZE + 1];
	int		**tab;

	s = get_dim(fd);
	if (s == 0)
		return (NULL);
	tab = make_tab();
	i = 0;
	i = handle_first_buff(s, block, tab, i);
	if (i == -1)
		return (NULL);
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		i = handle_first_buff(buff, block, tab, i);
		if (i == -1)
			return (NULL);
	}
	return (tab);
}

int		fif(char *s, int j, int *lastnl)
{
	if (s[j] == '\n')
	{
		if (*lastnl != g_dimension[1])
		{
			*lastnl = 0;
			return (-1);
		}
		*lastnl = 0;
	}
	return (0);
}

int		handle_first_buff(char *s, char *block, int **tab, int i)
{
	int			j;
	static int	lastnl = 0;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != block[0] && s[j] != block[2] && s[j] != '\n')
		{
			lastnl = 0;
			return (-1);
		}
		if (s[j] == block[2])
			percolation(tab, (i + j) % (g_dimension[1] + 1),
					(i + j) / (g_dimension[1] + 1));
		if (fif(s, j, &lastnl) == -1)
			return (-1);
		if (s[j] != '\n')
			lastnl++;
		j++;
	}
	return (i + j);
}

char	*get_dim(int fd)
{
	int		r[2];
	char	buff[BUFF_SIZE + 1];
	char	*s1;
	int		taille;

	taille = 0;
	s1 = ft_malloc_zero(taille + 1);
	while ((r[0] = read(fd, buff, BUFF_SIZE)))
	{
		g_dimension[1] = 0;
		s1 = ft_update(buff, s1, &taille, r[0]);
		r[1] = 0;
		while (s1[r[1]] != '\0')
		{
			if (s1[r[1]] == '\n')
			{
				return (s1);
			}
			g_dimension[1] = g_dimension[1] + 1;
			r[1]++;
		}
	}
	return (0);
}

int		first_line(char *vide, char *pleine, char *obstacle, int fd)
{
	char	buff[2];
	char	*tmp;
	int		r;

	tmp = ft_malloc_zero(1);
	r = read(fd, buff, 1);
	if (r == 0 || (buff[0] < '1' || buff[0] > '9'))
		return (-1);
	buff[r] = '\0';
	while (buff[0] <= '9' && buff[0] >= '0')
	{
		tmp = ft_update2(buff, tmp);
		r = read(fd, buff, 1);
		buff[r] = '\0';
	}
	g_dimension[0] = atoi(tmp);
	free(tmp);
	vide[0] = buff[0];
	read(fd, pleine, 1);
	read(fd, obstacle, 1);
	r = read(fd, buff, 1);
	if (r == 0 || buff[0] != '\n')
		return (-1);
	return (0);
}
