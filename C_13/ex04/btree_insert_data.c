#include "ft_btree.h"

void	btree_insert_data(t_btree **root, char *item, int
(*cmpf)(char *, char *))
{
	t_btree	*tmp;

	if (!*root)
		*root = btree_create_node(item);
	tmp = *root;
	while (tmp->left || tmp->right)
	{
		if (tmp->left)
		{
			if (cmpf(tmp->item, item) > 0)
				tmp = tmp->left;
			else
				if (tmp->right)
					tmp = tmp->right;
		}
		else
			tmp = tmp->right;
	}
	if (cmpf(tmp->item, item) > 0)
		tmp->left = btree_create_node(item);
	else
		tmp->right = btree_create_node(item);
}
