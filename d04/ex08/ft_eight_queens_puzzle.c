/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:06:57 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 11:07:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DIFF(a,b) ((a<b) ? (b-a) : (a-b))

int		solve(int n, int col, int *hist)
{
	int i;
	int j;
	int count;

	count = 0;
	if (col == n)
		count++;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < col && !(hist[j] == i) && !(DIFF(hist[j], i) == col - j))
			j++;
		if (j < col)
		{
			i++;
			continue;
		}
		hist[col] = i;
		count += solve(n, col + 1, hist);
		i++;
	}
	return (count);
}

int		ft_eight_queens_puzzle(void)
{
	int hist[8];

	return (solve(8, 0, hist));
}
