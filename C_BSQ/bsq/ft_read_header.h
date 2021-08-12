#ifndef FT_READ_HEADER_H
# define FT_READ_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_create_read_map_rules(char *filename);
char	*ft_read_create_map(char *filename);
void	ft_read_files(int	argc, char	**argv);
void	ft_read_files2(void);
int		main(int	argc, char	**argv);
int		ft_strlen(char *signs);
int		ft_check_dublicates(char *signs);
int		ft_is_printable(char *signs);
int		ft_line_len(char *filename);
int		ft_str_to_dec(char *signs);
int		ft_count_signs(char *signs);
int		ft_check_valid_map_rules(char	*signs);
void	ft_fill_signs(int	i, int	file, char **signs);
void	ft_pass_first_line(int *file, int *r_file, char *buf);
int		ft_ch_in_arr(char *signs, char ch);
int		ft_check_cols_valid_map(int	file, char	*signs, int	*prev_cols);
int		ft_valid_map(char *filename);
void	ft_fill_matrix(int	file, char	**res);
int		ft_check_allocated_valid(char	*ptr);
void	ft_read_files(int	argc, char	**argv);
int		ft_process_process(int *i, char *buf, char *filename, int *r_file);
int		ft_process_filename2(char *buf, char *filename, int
			*i, int *r_file);
int		ft_check_buf(char buf, char *filename);
void	ft_create_int_matrix(char *matrix_char, char obstacle, char full);
void	ft_putstr(char	*str);

#endif