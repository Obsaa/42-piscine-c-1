/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 20:56:47 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/03 20:07:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char	ch1;
	char	ch2;
	char	ch3;

	ch1 = '0' - 1;
	while (++ch1 <= '9')
	{
		ch2 = ch1;
		while (++ch2 <= '9')
		{
			ch3 = ch2;
			while (++ch3 <= '9')
			{
				if (ch1 != '0' || ch2 != '1' || ch3 != '2')
					ft_putchar(',');
				if (ch1 != '0' || ch2 != '1' || ch3 != '2')
					ft_putchar(' ');
				ft_putchar(ch1);
				ft_putchar(ch2);
				ft_putchar(ch3);
			}
		}
	}
}
