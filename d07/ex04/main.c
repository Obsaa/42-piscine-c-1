#include <stdio.h>

int		count_words(char *str);
char 	**ft_split_whitespaces(char *str);

int		main()
{
	char	*phrase = " \t  m\ny name is\t hello\n\t  world\t \n";
	char	**table = ft_split_whitespaces(phrase);

	printf("%s\n", phrase);
	while (*table)
		printf("%s, ", *table++);
	return 0;
}
