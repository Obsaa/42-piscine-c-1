/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:55:19 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 10:39:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	f;
	int fn;

	i = 1;
	f = 1;
	fn = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		fn = f * i;
		if (fn / i != f)
			return (0);
		i++;
		f = fn;
	}
	return (f);
}
