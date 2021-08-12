#include "ft_read_header.h"

int	ft_count_signs(char *signs)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (signs[i] != '\0')
		i++;
	i++;
	while (signs[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

int	ft_check_valid_map_rules(char	*signs)
{
	if (ft_str_to_dec(signs) == 0)
		return (0);
	else if (ft_count_signs(signs) != 3)
		return (0);
	else if (ft_check_dublicates(signs) == -1)
		return (0);
	else if (ft_is_printable(signs) == -1)
		return (0);
	return (1);
}

void	ft_fill_signs(int	i, int	file, char **signs)
{
	int		r_file;
	char	buf;
	int		j;

	j = 0;
	r_file = read(file, &buf, 1);
	while (r_file > 0 && i >= 0 && buf != '\n')
	{
		if (i - 3 != 0)
		{
			signs[0][j] = buf;
			r_file = read(file, &buf, 1);
		}
		else if (i - 3 == 0)
			signs[0][j] = '\0';
		j++;
		i--;
	}
	signs[0][j] = '\0';
}
