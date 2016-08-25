/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:09:11 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 21:09:03 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_io.h"

char *ft_update(char *buff, char *s, int *taille, int r)
{
	char *tmp;

	buff[r] = '\0';
	*taille = *taille + r;
	tmp = ft_malloc_zero(*taille + 1);
	ft_strcpy(tmp, s);
	free(s);
	s = ft_malloc_zero(*taille + 1);
	ft_strcpy(s, tmp);
	s = ft_append(s, buff);
	free(tmp);
	return (s);
}

char *ft_update2(char *buff, char *tmp)
{
	char		*s2;
	static int	taille = 0;

	taille = taille + 1;
	s2 = ft_malloc_zero(taille + 1);
	ft_strcpy(s2, tmp);
	free(tmp);
	tmp = ft_malloc_zero(taille + 1);
	ft_strcpy(tmp, s2);
	tmp = ft_append(tmp, buff);
	free(s2);
	return (tmp);
}
