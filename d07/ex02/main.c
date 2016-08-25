#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main()
{
	int *range;
	int i = 0;
	int size;

	size = ft_ultimate_range(&range,20,16);
	printf("size:%i",size);
	printf("\ni,range[0][i], &:\n");
	while (i < size)
	{
		printf("%i, %i, %p\n",i, range[i], &range[i]);
		i++;
	}
	return 0;
}
