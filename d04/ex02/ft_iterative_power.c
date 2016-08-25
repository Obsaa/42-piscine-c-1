/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:15:41 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 10:48:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nb_orig;
	int	nb_prev;

	nb_orig = nb;
	i = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb_prev = nb;
		nb *= nb_orig;
		if (nb / nb_orig != nb_prev)
			return (0);
		i++;
	}
	return (nb);
}
