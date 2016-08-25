void	ft_foreach(int *tab,int length, void(*f)(int));

void	ft_putnbr(int nb);

int		main()
{
	int		tab[5] = {1, 14, 17, 42, 16};

	ft_foreach(tab,5,&ft_putnbr);
	return 0;
}
