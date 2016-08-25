#include <stdio.h>

char 	**ft_split(char *str, char *charset);

int		main()
{
	int		i = 0;
	char	*phrase = " k  my name isk hellokk  worldk";
	char	*charset = "mk";
	char	**table = ft_split(phrase, charset);

	printf("phrase  = '%s'\n", phrase);
	printf("charset = '%s'\n", charset);
	while (table[i] != 0x0)
		printf("'%s'\n", table[i++]);
	return 0;
}
