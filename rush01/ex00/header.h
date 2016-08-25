/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 11:59:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/20 23:17:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# define CELL_MOINS_UN(x) (3 * (x / 3) + (x - 1) % 3)
# define CELL_PLUS_UN(x) (3 * (x / 3) + (x + 1) % 3)

extern int	g_count;
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_print_sudoku(char **grid);
int		ft_solver(char ***grid, int line, int col);
int		ft_is_valid(char **grid, char number, int line, int col);
#endif
