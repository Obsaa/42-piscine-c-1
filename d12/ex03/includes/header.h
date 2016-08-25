/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 20:16:16 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/19 15:40:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 10
# define IS_DIV(a, b) (!((a) % (b)))
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
void	ft_bad_fd(char *str);
void	ft_bad_name(char *str);
void	ft_putnbr_base16(int nbr, int format);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_hexdump(void *addr, unsigned int size, int option);
#endif
