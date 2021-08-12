#include "ft_square.h"

extern int	g_lines;
extern int	g_cols;

void	ft_fill2_int_matrix(t_matrix matrix, char *matrix_char, char
full, char obstacle)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix.lines)
	{
		j = 0;
		while (j < matrix.colums)
		{
			if (i == 0 && j != 0)
				matrix.arr[i][j] += matrix.arr[i][j - 1];
			else if (j == 0 && i != 0)
				matrix.arr[i][j] += matrix.arr[i - 1][j];
			else if (i != 0 && j != 0)
				matrix.arr[i][j] += (matrix.arr[i - 1][j]
						+ matrix.arr[i][j - 1]) - matrix.arr[i - 1][j - 1];
			j++;
		}
		i++;
	}
	ft_square(matrix, matrix_char, full, obstacle);
}

void	ft_fill1_int_matrix(t_matrix matrix, char *matrix_char, char
obstacle, char full)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix.lines)
	{
		j = 0;
		while (j < matrix.colums)
		{
			if (*(matrix_char + i * matrix.colums + j) == obstacle)
				matrix.arr[i][j] = 1;
			else
				matrix.arr[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_fill2_int_matrix(matrix, matrix_char, full, obstacle);
}

void	ft_create_int_matrix(char *matrix_char, char obstacle, char full)
{
	int			i;
	t_matrix	matrix_int;

	matrix_int.lines = g_lines;
	matrix_int.colums = g_cols;
	matrix_int.arr = (int **)malloc(sizeof(int *) * matrix_int.lines);
	if (matrix_int.arr == NULL)
	{
		free(matrix_char);
		exit (-1);
	}
	i = 0;
	while (i < matrix_int.lines)
	{
		matrix_int.arr[i] = malloc(sizeof(int) * matrix_int.colums);
		if (matrix_int.arr[i] == NULL)
		{
			free(matrix_char);
			free(matrix_int.arr);
			exit (-1);
		}
		i++;
	}
	ft_fill1_int_matrix(matrix_int, matrix_char, obstacle, full);
}
