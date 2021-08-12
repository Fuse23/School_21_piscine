#include <unistd.h>
#include <stdio.h>

int	len(char *str, int nbr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (-1);
		i++;
	}
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (-1);
	}
	return (i);
}

int	ft_double(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] != '\0')
	{
		j = i + 1;
		while (str[j + 1] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	int	negativ(int n)
{
	long int	s;

	s = n;
	if (n < 0)
	{
		write(1, "-", 1);
		s *= -1;
		return (s);
	}
	return (s);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			res[50];
	int			i;
	int			l;
	long int	t;

	i = 0;
	l = len(base, nbr);
	if (l < 2)
		return ;
	if (ft_double(base) > 0)
		return ;
	t = negativ(nbr);
	while (t != 0)
	{	
		res[i] = t % l;
		t /= l;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &base[res[i]], 1);
		i--;
	}
}