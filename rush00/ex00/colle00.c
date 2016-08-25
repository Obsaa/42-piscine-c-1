/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axalves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:28:14 by axalves           #+#    #+#             */
/*   Updated: 2016/08/06 11:03:32 by axalves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int width, char a, char b)
{
	int i;

	if (width == 1)
	{
		ft_putchar(a);
	}
	if (width > 1)
	{
		ft_putchar(a);
		i = 0;
		while (i < width - 2)
		{
			ft_putchar(b);
			i = i + 1;
		}
		ft_putchar(a);
	}
	ft_putchar('\n');
}

void	colle(int width, int height)
{
	int i;

	if (height == 1)
	{
		ft_print_line(width, 'o', '-');
	}
	if (height > 1)
	{
		ft_print_line(width, 'o', '-');
		i = 0;
		while (i < height - 2)
		{
			ft_print_line(width, '|', ' ');
			i = i + 1;
		}
		ft_print_line(width, 'o', '-');
	}
}
