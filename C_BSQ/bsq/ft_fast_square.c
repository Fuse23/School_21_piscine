#include "ft_square.h"

extern int	g_lines;
extern int	g_cols;

int	create_square(t_matrix matrix, int x, int y, int size)
{
	int	a;
	int	b;
	int	c;
	int	d;

	if (x + size >= matrix.lines || y + size >= matrix.colums)
		return (1);
	a = matrix.arr[x][y];
	b = matrix.arr[x][y + size];
	c = matrix.arr[x + size][y];
	d = matrix.arr[x + size][y + size];
	if (x == 0 && y == 0)
		return (d);
	else if (x == 0 && y != 0)
		return (d - c);
	else if (x != 0 && y == 0)
		return (d - b);
	else
		return (d - c - b + a);
}

void	ft_square_one_line(char *matrix, char full, char obstacle)
{
	int	i;

	i = 0;
	while (i < g_cols)
	{
		if (*(matrix + i) != obstacle)
		{
			*(matrix + i) = full;
			ft_print_one_line(matrix);
			return ;
		}
		i++;
	}
	ft_print_one_line(matrix);
}

void	ft_nado(t_square *square, int max, int i, int j)
{
	square->max = max + 1;
	square->x = i;
	square->y = j;
}

void	ft_nodo2(t_matrix matrix, char *matrix_char, char full)
{
	int			i;
	int			j;
	t_square	square;

	square.max = 0;
	square.x = -1;
	square.y = -1;
	i = 0;
	while (i < matrix.lines)
	{
		j = 0;
		while (j < matrix.colums)
		{
			while (create_square(matrix, i, j, square.max + 1) <= 0)
				ft_nado(&square, square.max, i, j);
			j++;
		}
		i++;
	}
	ft_print(matrix, matrix_char, square, full);
}

void	ft_square(t_matrix matrix, char *matrix_char, char full, char obstacle)
{
	if (matrix.lines == 1)
	{
		ft_square_one_line(matrix_char, full, obstacle);
		free(matrix.arr);
		return ;
	}
	else
		ft_nodo2(matrix, matrix_char, full);
}
