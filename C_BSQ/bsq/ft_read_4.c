#include "ft_read_header.h"

extern int		g_lines;
extern int		g_cols;
extern char		*g_map;
extern char		*g_signs;

int	ft_check_allocated_valid(char	*ptr)
{
	if (ptr == NULL)
	{
		ft_putstr("map error");
		free(ptr);
		return (-1);
	}
	return (1);
}

void	ft_read_files(int	argc, char	**argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		g_signs = ft_create_read_map_rules(argv[i]);
		if (ft_check_allocated_valid(g_signs) == -1)
		{
			i++;
			continue ;
		}
		g_map = ft_read_create_map(argv[i]);
		if (ft_check_allocated_valid(g_map) == -1)
		{
			i++;
			continue ;
		}
		ft_create_int_matrix(g_map, g_signs[ft_strlen(g_signs) - 2],
			g_signs[ft_strlen(g_signs) - 1]);
		i++;
	}
}

int	ft_process_process(int *i, char *buf, char *filename, int *r_file)
{
	*i = 0;
	if (*buf == '\n')
	{
		free(filename);
		return (-1);
	}
	*r_file = read(1, buf, 1);
	return (0);
}

int	ft_process_filename2(char *buf, char *filename, int
*i, int *r_file)
{
	int	code;

	filename[*i] = '\0';
	g_signs = ft_create_read_map_rules(filename);
	if (ft_check_allocated_valid(g_signs) == -1)
	{
		code = ft_process_process(i, buf, filename, r_file);
		return (code);
	}
	g_map = ft_read_create_map(filename);
	if (ft_check_allocated_valid(g_map) == -1)
	{
		code = ft_process_process(i, buf, filename, r_file);
		return (code);
	}
	ft_create_int_matrix(g_map, g_signs[ft_strlen(g_signs) - 2],
		g_signs[ft_strlen(g_signs) - 1]);
	*i = 0;
	return (1);
}

int	ft_check_buf(char buf, char *filename)
{
	if (buf == '\n')
	{
		free(filename);
		return (-1);
	}
	return (0);
}
