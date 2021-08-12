#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*tmp_data;
	t_list	*tmp_i;
	t_list	*tmp_j;

	tmp_i = *begin_list;
	while (tmp_i->next)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (cmp(tmp_i->data, tmp_j->data) > 0)
			{
				tmp_data = tmp_i->data;
				tmp_i->data = tmp_j->data;
				tmp_j->data = tmp_data;
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list
*begin_list2, int (*cmp)())
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
	ft_list_sort(begin_list1, cmp);
}
