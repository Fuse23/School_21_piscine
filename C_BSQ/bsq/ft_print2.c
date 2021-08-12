#include "ft_square.h"

extern int	g_cols;

void	ft_print_one_line(char *matrix)
{
	int	i;

	i = 0;
	while (i < g_cols)
	{
		write(1, (matrix + i), 1);
		i++;
	}
	write(1, "\n", 1);
	free(matrix);
}
