#ifndef FT_RASH_H
# define FT_RASH_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;
void	ft_print(char *str);
int ft_strlen(char *str);
char    *find_key(t_dict *dict, char digit, int len);
char    *find_key_2(t_dict *dict, char digit);
void	ft_to_letters(t_dict *dict, char *number);

#endif