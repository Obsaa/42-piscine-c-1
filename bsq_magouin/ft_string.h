/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 08:50:34 by jcamhi            #+#    #+#             */
/*   Updated: 2015/07/30 21:10:04 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

char	*ft_append(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
char	*ft_malloc_zero(int nb);
int		ft_strlen(char *s);
int		**trans_tab(char *tab, int heigth, int width, char vide, char obstacle);
#endif
