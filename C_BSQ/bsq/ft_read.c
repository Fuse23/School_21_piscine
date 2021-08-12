#include "ft_read_header.h"

int		g_lines;
int		g_cols;
char	*g_map;
char	*g_signs;

char	*ft_create_read_map_rules(char *filename)
{
	int		file;
	int		i;
	char	*signs;

	file = open(filename, O_RDONLY);
	i = ft_line_len(filename);
	if (i == -1)
		return (NULL);
	signs = malloc(sizeof(char) * (i + 2));
	if (file == -1)
	{
		return (NULL);
		return (0);
	}
	ft_fill_signs(i, file, &signs);
	close(file);
	if (ft_check_valid_map_rules(signs) == 0)
		return (NULL);
	return (signs);
}

char	*ft_read_create_map(char *filename)
{
	int		file;
	char	*res;

	if (ft_valid_map(filename) == -1)
		return (NULL);
	res = malloc(g_lines * g_cols * sizeof(char));
	if (res == NULL)
		return (NULL);
	file = open(filename, O_RDONLY, 0);
	ft_fill_matrix(file, &res);
	close(file);
	return (res);
}

void	ft_read_files2(void)
{
	int		i;
	int		code;
	int		r_file;
	char	*filename;
	char	buf;

	i = 0;
	r_file = read(1, &buf, 1);
	filename = malloc(256 * sizeof(char));
	while (r_file != 0)
	{
		if (buf == ' ' || buf == '\n')
		{
			code = ft_process_filename2(&buf, filename, &i, &r_file);
			if (code == -1)
				return ;
			else if (code == 0)
				continue ;
		}
		else
			filename[i++] = buf;
		if (ft_check_buf(buf, filename) == -1)
			return ;
		r_file = read(1, &buf, 1);
	}
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

int	main(int	argc, char	**argv)
{
	g_signs = NULL;
	g_map = NULL;
	if (argc != 1)
		ft_read_files(argc, argv);
	else
		ft_read_files2();
	free(g_signs);
	return (0);
}
