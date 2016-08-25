/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:08:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/05 15:03:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DIFF(a,b) ((a<b) ? (b-a) : (a-b))

void	ft_putchar(char c);

void	print_layout(int *list)
{
	int	i;

	i = 0;
	while (i < 8)
		ft_putchar((char)list[i++] + 48 + 1);
	ft_putchar('\n');
}

int		solve_2(int n, int col, int *hist)
{
	int i;
	int j;
	int count;

	count = 0;
	if (col == n)
		count++;
	if (col == n)
		print_layout(hist);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < col && !(hist[j] == i) && !(DIFF(hist[j], i) == col - j))
			j++;
		if (j < col)
			i++;
		if (j < col)
			continue;
		hist[col] = i;
		count += solve_2(n, col + 1, hist);
		i++;
	}
	return (count);
}

int		ft_eight_queens_puzzle_2(void)
{
	int hist[8];

	return (solve_2(8, 0, hist));
}
