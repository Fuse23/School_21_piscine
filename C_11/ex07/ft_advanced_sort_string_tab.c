#include <unistd.h>

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = i + 1;
		while (tab[j] != NULL)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
