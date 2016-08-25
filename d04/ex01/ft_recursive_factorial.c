/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:04:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 10:02:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	f;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		f = ft_recursive_factorial(nb - 1);
		if ((nb * f) / nb != f)
			return (0);
		return (nb * f);
	}
}
