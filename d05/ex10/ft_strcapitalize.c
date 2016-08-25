/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:50:19 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/07 22:09:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alphanum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char *s;

	s = str;
	while (*s != '\0')
	{
		if (ft_is_alphanum(*(s - 1)) && *s >= 'A' && *s <= 'Z')
			*s += 32;
		if (!ft_is_alphanum(*(s - 1)) && *s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
	return (str);
}
