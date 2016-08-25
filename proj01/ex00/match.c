/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 11:24:25 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/13 11:24:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	match(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*')
	{
		if (!*s1)
			return (match(s1, s2 + 1));
		else
			return (match(s1 + 1, s2) || match(s1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else
		return (0);
}
