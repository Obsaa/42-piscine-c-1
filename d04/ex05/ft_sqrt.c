/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:52:22 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/07 17:46:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SQ(x) (x * x)

int	ft_sqrt(int nb)
{
	int	guess;
	int	low;
	int	high;

	low = 0;
	high = 46342;
	while (1)
	{
		guess = (high + low) / 2;
		if (SQ(guess) > nb)
			high = guess;
		else if (SQ(guess) < nb)
			low = guess;
		if (SQ(guess) == nb)
			return (guess);
		if ((high - low) <= 1)
		{
			return (0);
		}
	}
}
