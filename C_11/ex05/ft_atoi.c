#include "ft_h.h"

void	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == ' '))
		i++;
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	ft_is_space(str);
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] != '-' && str[i] != '+')
		if (str[i] < '0' || str[i] > '9')
			return (0);
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * sign);
}
