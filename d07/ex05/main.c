#include <unistd.h>

void	ft_print_words_tables(char **tab);
char	**ft_split_whitespaces(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main()
{
	char	*phrase = "\n\n thi s is a\t \t test phrase\n \n\t";
	char	**table;

	table = ft_split_whitespaces(phrase);
	ft_print_words_tables(table);
	return 0;
}
