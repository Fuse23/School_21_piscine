#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*end;
	t_list	*tmp;

	end = ft_create_elem(data);
	if (!*begin_list)
		*begin_list = end;
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = end;
	}
}
