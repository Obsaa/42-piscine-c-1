#include <stdio.h>
int		*ft_range(int min, int max);

int		main()
{
	int *table;
	int i = 0;

	table = ft_range(10,12);

	while (table[i])
	{
		printf("%i, %i\n",i, table[i]);
		i++;
	}
	return 0;
}
