#ifndef FT_SQUARE_H
# define FT_SQUARE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_square
{
	int	x;
	int	y;
	int	max;
}	t_square;

typedef struct s_matrix
{
	int	lines;
	int	colums;
	int	**arr;
}	t_matrix;

void	ft_square(t_matrix matrix, char *matrix_char, char full, char obstacle);
void	ft_print(t_matrix matrix_int, char *matrix_char, t_square
			square, char full);
void	ft_print_one_line(char *matrix);

#endif