/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:59:39 by falarm            #+#    #+#             */
/*   Updated: 2021/07/29 22:10:56 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*tmp;
	int				i;
	long long int	p;

	i = 0;
	p = (long long)max - (long long)min;
	if (p > 2147483647)
		return (NULL);
	tmp = malloc(p * sizeof(int));
	if (min >= max)
		return (NULL);
	if (tmp == NULL)
		return (NULL);
	while (min < max)
	{
		tmp[i] = min;
		min++;
		i++;
	}
	return (tmp);
}
