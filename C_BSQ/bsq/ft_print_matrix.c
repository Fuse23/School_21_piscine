#include "ft_square.h"

void	ft_print_x_y(t_matrix matrix_int, char *matrix_char, t_square
square, char full)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_int.lines)
	{
		j = 0;
		while (j < matrix_int.colums)
		{
			if (i <= square.max + square.x && i >= square.x
				&& j <= square.max + square.y && j >= square.y)
				write(1, &full, 1);
			else
				write(1, (matrix_char + i * matrix_int.colums + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_x(t_matrix matrix_int, char *matrix_char, t_square
square, char full)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_int.lines)
	{
		j = 0;
		while (j < matrix_int.colums)
		{
			if (i <= square.max + square.x && i >= square.x
				&& j <= square.max + square.y && j > square.y)
				write(1, &full, 1);
			else
				write(1, (matrix_char + i * matrix_int.colums + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_y(t_matrix matrix_int, char *matrix_char, t_square
square, char full)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_int.lines)
	{
		j = 0;
		while (j < matrix_int.colums)
		{
			if (i <= square.max + square.x && i > square.x
				&& j <= square.max + square.y && j >= square.y)
				write(1, &full, 1);
			else
				write(1, (matrix_char + i * matrix_int.colums + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_just_print(t_matrix matrix_int, char *matrix_char, t_square
square, char full)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_int.lines)
	{
		j = 0;
		while (j < matrix_int.colums)
		{
			if (i <= square.max + square.x && i > square.x
				&& j <= square.max + square.y && j > square.y)
				write(1, &full, 1);
			else
				write(1, (matrix_char + i * matrix_int.colums + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print(t_matrix matrix_int, char *matrix_char, t_square
square, char full)
{
	int	i;

	i = 0;
	if (square.x == 0 && square.y == 0)
		ft_print_x_y(matrix_int, matrix_char, square, full);
	else if (square.x == 0 && square.y != 0)
		ft_print_x(matrix_int, matrix_char, square, full);
	else if (square.x != 0 && square.y == 0)
		ft_print_y(matrix_int, matrix_char, square, full);
	else
		ft_just_print(matrix_int, matrix_char, square, full);
	free(matrix_char);
	free(matrix_int.arr);
}
