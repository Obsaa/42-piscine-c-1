#include <stdio.h>

int		ft_count_if(char **tab, int(*f)(char *));

int		equals_4(char* str)
{
	if (str[0] == '4' && str[1] == '\0')
		return 1;
	return 0;
}

int		main()
{
	char	*(tab[6]) = {"4","facebook", "4", "0google", "0","4"};
	printf("%i\n", ft_count_if(tab, &equals_4));
}
