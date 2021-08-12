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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;

	tmp = ft_create_elem(data);
	if (*begin_list)
		tmp->next = *begin_list;
	*begin_list = tmp;
	ft_list_sort(begin_list, cmp);
}
