#include "ft_read_header.h"

int	ft_strlen(char *signs)
{
	int	i;

	i = 0;
	while (signs[i] != '\0')
		i++;
	i++;
	while (signs[i] != '\0')
		i++;
	return (i);
}

int	ft_check_dublicates(char *signs)
{
	int	i;
	int	j;

	i = 0;
	while (signs[i] != '\0')
		i++;
	i++;
	while (signs[i] != '\0')
	{
		j = i + 1;
		while (signs[j] != '\0')
		{
			if (signs[i] == signs[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_printable(char *signs)
{
	int	i;

	i = 0;
	while (signs[i] != '\0')
	{
		if (signs[i] < 32 || signs[i] > 126)
			return (-1);
		i++;
	}
	i++;
	while (signs[i] != '\0')
	{
		if (signs[i] < 32 || signs[i] > 126)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_line_len(char *filename)
{
	int		i;
	int		file;
	int		r_file;
	char	buf;

	i = 0;
	file = open(filename, O_RDONLY, 0);
	r_file = read(file, &buf, 1);
	while (r_file > 0 && buf != '\n')
	{
		i++;
		r_file = read(file, &buf, 1);
	}
	if (r_file == -1)
		return (-1);
	close(file);
	return (i);
}

int	ft_str_to_dec(char *signs)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (signs[i] != '\0')
		res = res * 10 + (signs[i++] - '0');
	return (res);
}
