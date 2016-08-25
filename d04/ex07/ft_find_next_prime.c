/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:56:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/07 17:45:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime2(int nb)
{
	int	i;

	if ((nb % 2 == 0 && nb != 2) || nb <= 1)
		return (0);
	i = 3;
	while (i * i <= nb)
	{
		if ((nb % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	nb += (nb % 2) ? 0 : 1;
	while (!ft_is_prime2(nb))
		nb += 2;
	return (nb);
}
