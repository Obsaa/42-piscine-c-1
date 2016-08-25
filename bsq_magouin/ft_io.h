/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 09:36:44 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 21:23:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 2

int g_dimension[2];

int		first_line(char *vide, char *plein, char *obstacle, int fd);
int		handle_first_buff(char *s, char *block, int **tab, int i);
int		ft_atoi(char *s);
void	make_cadre(int **tab, int target, int longueur, int hauteur);
void	percolation(int **tab, int x, int y);
void	print_tab(int **tab, int longueur, int hauteur);
void	recursifg(int **tab, int x, int y, int value);
void	recursifd(int **tab, int x, int y, int value);
void	recursifh(int **tab, int x, int y, int value);
void	recursifb(int **tab, int x, int y, int value);
char	*get_dim(int fd);
int		**make_tab(void);
int		**handle_buffer(char *block, int fd);
void	print_result(int **tab, int *max, char *block);
char	*ft_update(char *buff, char *s, int *taille, int r);
char	*ft_update2(char *buff, char *tmp);
#endif
