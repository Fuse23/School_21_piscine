#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	next = NULL;
	current = begin_list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	begin_list = prev;
}
