int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (up)
				return (0);
			down = 1;
		}
		if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (down)
				return (0);
			up = 1;
		}
		i++;
	}
	return (1);
}
