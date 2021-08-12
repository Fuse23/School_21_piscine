#include <unistd.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_base(char *base, char s)
{
	int	i;

	i = 0;
	if (len(base) < 2)
		return (-1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (-1);
		if (s == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	degree(n, d)
{
	int	a;

	a = n;
	if (d == 0)
		return (1);
	while (d > 1)
	{
		n *= a;
		d--;
	}
	return (n);
}

int	to_ten(char *t, char *b)
{
	int	n;
	int	l;
	int	ln;
	int	i;

	n = 0;
	i = 0;
	l = len(b);
	ln = len(t);
	while (t[i] != '\0')
	{
		n += is_base(b, t[i]) * degree(l, (ln - i - 1));
		i++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	char	t[1024];
	int		sign;
	int		i;

	sign = 1;
	i = 0;
    while (*str != '\0'
		&& (*str == '\n' || *str == '\t' || *str == '\r'
			|| *str == '\f' || *str == '\v'))
            str++;
	while (*str != '\0'
		&& (*str == '-' || *str == '+' || *str == ' '))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str != ' ' && *str != '\n' && *str != '\t' 
        && *str != '\r' && *str != '\f' && *str != '\v' 
        && !is_base(base, *str))
		return (0);
	while ((*str != '\0') && (is_base(base, *str) > 0))
	{
		t[i++] = *str;
		str++;
	}
	return (sign * to_ten(t, base));
}