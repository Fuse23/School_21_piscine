int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			t++;
		i++;
	}
	return (t);
}
