#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	list = *begin_list1;
	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		while (list->next)
			list = list->next;
		list->next = begin_list2;
	}
}
