#include <stdio.h>

char	*ft_concat_params(int argc, char **argv);

int main(int argc, char **argv)
{
	char	*concat = ft_concat_params(argc, argv);
	printf("%s", concat);
	return 0;
}
