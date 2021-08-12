/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:27:00 by falarm            #+#    #+#             */
/*   Updated: 2021/07/29 22:10:16 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	long long int	p;

	i = 0;
	p = (long long)max - (long long)min;
	if (p > 2147483647)
		return (-1);
	*range = malloc(p * sizeof(int));
	if (*range == NULL)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (i);
}
