#include "ft_h.h"

void	ft_print(char *t, int i)
{
	while (i >= 0)
	{
		write(1, &t[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char		t[50];
	int			i;
	long int	n;

	n = nb;
	i = 0;
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		t[i] = (n % 10) + '0';
		n -= (n % 10);
		n /= 10;
		i++;
	}
	i--;
	ft_print(t, i);
}
