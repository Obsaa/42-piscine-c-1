/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:49:12 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/15 22:25:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	size;
	int	cmp;
	int i;

	size = 1;
	i = 0;
	cmp = 0;
	while (1)
	{
		cmp += (s1[i] - s2[i]);
		if (i >= (int)n - 1)
			return (cmp);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (cmp);
		if (s1[i] == s2[i])
			i++;
		else
			return (cmp);
	}
}
