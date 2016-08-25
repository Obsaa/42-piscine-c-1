#include <stdio.h>
#include <string.h>
char	*ft_strdup(char *src);

int		main()
{
	char	*in="hello world";
	char	*out1 = strdup(in);
	char	*out2 = ft_strdup(in);

	printf("in: %s, %p\n", in, &in);
	printf("strdup: %s, %p\n", out1, &out1);
	printf("ft_strdup: %s, %p\n", out2, &out2);

	return 0;
}
