#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list;
		(*free_fct)(tmp->data);
		begin_list = tmp->next;
		free(tmp);
	}
}
