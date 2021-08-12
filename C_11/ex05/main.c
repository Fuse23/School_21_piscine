#include "ft_h.h"

int	znak(char *z)
{
	if (z[0] != '+' && z[0] != '-' && z[0] != '*'
		&& z[0] != '/' && z[0] != '%')
		return (0);
	if (z[0] == '+' && z[1] == '\0')
		return (1);
	if (z[0] == '-' && z[1] == '\0')
		return (2);
	if (z[0] == '*' && z[1] == '\0')
		return (3);
	if (z[0] == '/' && z[1] == '\0')
		return (4);
	if (z[0] == '%' && z[1] == '\0')
		return (5);
	return (0);
}

void	number(int a, int b, char *z)
{
	if (znak(z) == 1)
		ft_putnbr(sum(a, b));
	if (znak(z) == 2)
		ft_putnbr(minus(a, b));
	if (znak(z) == 3)
		ft_putnbr(multiply(a, b));
	if (znak(z) == 4)
	{
		if (b == 0)
			write(1, "Stop : division by zero\n", 25);
		else
			ft_putnbr(devide(a, b));
	}
	if (znak(z) == 5)
	{
		if (b == 0)
			write(1, "Stop : modulo by zero\n", 23);
		else
			ft_putnbr(modulo(a, b));
	}
	if (znak(z) == 0)
		ft_putnbr(0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc > 4 || argc < 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	number(a, b, argv[2]);
	return (0);
}
