/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:01:59 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/10 16:15:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_size_21(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if (str[i] < 32 || str[i] > 126)
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		get_pos(char c, char *str)
{
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (c != *s)
	{
		if (!*s)
			return (s - str);
		s++;
	}
	return (s - str);
}

int		ft_check_str(char *str, char *base, int base_size)
{
	while (*str)
	{
		if (!(get_pos(*str, base) < base_size || *str == '-' || *str == '+'))
			return (0);
		str++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		base_size;
	int		res;
	int		sign;

	base_size = get_size_21(base);
	res = 0;
	sign = 1;
	if (!ft_check_str(str, base, base_size))
		return (0);
	if (base_size > 1)
	{
		if (*str == '-' || *str == '+')
		{
			if (get_pos(*(str + 1), base) < base_size)
			{
				sign = (*str == '+') ? 1 : -1;
				str++;
			}
			else
				return (0);
		}
		while (get_pos(*str, base) < base_size)
			res = res * base_size + sign * get_pos(*str++, base);
	}
	return (res);
}
