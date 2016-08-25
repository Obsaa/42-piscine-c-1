/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:58:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/09 17:39:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	n;

	d = dest;
	s = src;
	n = size;
	if (n != 0)
	{
		while (!--n)
		{
			if ((*d++ = *s++) == '\0')
				break ;
		}
	}
	if (n == 0 && size != 0)
		*d = '\0';
	while (*s)
		s++;
	return (s - src);
}
