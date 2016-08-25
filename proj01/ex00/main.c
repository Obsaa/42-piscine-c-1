/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 19:10:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/14 19:10:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	match(char *a, char *b);

int	main(void)
{
	char a[100];
	char b[100];

	strcpy(a, "est");
	strcpy(b, "t");
	printf("%s, %s: %i\n", a, b, match(a, b));
	strcpy(a, "test");
	strcpy(b, "*t");
	printf("%s, %s: %i\n", a, b, match(a, b));
	strcpy(a, "test");
	strcpy(b, "*t*");
	printf("%s, %s: %i\n", a, b, match(a, b));
	strcpy(a, "test");
	strcpy(b, "*test*");
	printf("%s, %s: %i\n", a, b, match(a, b));
}
