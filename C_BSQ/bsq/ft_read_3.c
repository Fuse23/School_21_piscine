#include "ft_read_header.h"

extern int		g_lines;
extern int		g_cols;
extern char		*g_map;
extern char		*g_signs;

void	ft_pass_first_line(int *file, int *r_file, char *buf)
{
	*r_file = read(*file, &buf[0], 1);
	while (*r_file > 0 && *buf != '\n')
		*r_file = read(*file, &buf[0], 1);
}

int	ft_ch_in_arr(char *signs, char ch)
{
	int	i;

	i = 0;
	while (signs[i] != '\0')
		i++;
	i++;
	if (signs[i] == ch || signs[i + 1] == ch)
		return (1);
	return (-1);
}

int	ft_check_cols_valid_map(int	file, char	*signs, int	*prev_cols)
{
	int		r_file;
	char	buf;

	ft_pass_first_line(&file, &r_file, &buf);
	r_file = read(file, &buf, 1);
	while (r_file > 0)
	{
		if (buf == '\n')
		{
			if (*prev_cols != -1 && g_cols != *prev_cols)
				return (-1);
			g_lines = g_lines + 1;
			*prev_cols = g_cols;
			g_cols = 0;
		}
		else
		{
			if (ft_ch_in_arr(signs, buf) == -1)
				return (-1);
			g_cols = g_cols + 1;
		}
		r_file = read(file, &buf, 1);
	}
	return (0);
}

int	ft_valid_map(char *filename)
{
	int		prev_cols;
	int		file;

	prev_cols = -1;
	g_cols = 0;
	g_lines = 0;
	file = open(filename, O_RDONLY, 0);
	if (ft_check_cols_valid_map(file, g_signs, &prev_cols) == -1)
		return (-1);
	close(file);
	g_cols = prev_cols;
	if (g_lines != ft_str_to_dec(g_signs))
		return (-1);
	return (1);
}

void	ft_fill_matrix(int	file, char	**res)
{
	int		r_file;
	char	buf;
	int		j;
	int		i;

	j = 0;
	i = 0;
	ft_pass_first_line(&file, &r_file, &buf);
	r_file = read(file, &buf, 1);
	while (r_file > 0 && i < g_lines)
	{
		if (buf == '\n')
		{
			j = 0;
			i++;
		}
		else
		{
			*(res[0] + i * g_cols + j) = buf;
			j++;
		}
		r_file = read(file, &buf, 1);
	}
}
