/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:34:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 13:58:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int fibm;
	int fibmm;

	if (index >= 47)
		return (0);
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	fibm = ft_fibonacci(index - 1);
	fibmm = ft_fibonacci(index - 2);
	return (fibm + fibmm);
}
