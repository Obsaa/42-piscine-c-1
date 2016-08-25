#include <stdio.h>
#include <string.h>
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main()
{
	char	nbr[100] = "-AF";
	char	b_in[100] = "0123456789ABCDEF";
	char	b_out[100] = "ok";
	char	*out;

	printf("nbr = '%s'\nb_in= '%s'\nb_out= '%s'\n", nbr, b_in, b_out);
	out = ft_convert_base(nbr, b_in, b_out);
	printf("out = '%s'\n", out);

	strcpy(nbr, "11111");
	strcpy(b_in, "1qDQegUMsyB");
	strcpy(b_out, "1qDQegUMsyB");
	printf("\n");
	printf("nbr = '%s'\nb_in= '%s'\nb_out= '%s'\n", nbr, b_in, b_out);
	out = ft_convert_base(nbr, b_in, b_out);
	printf("out = '%s'\n", out);
	return 0;
}
