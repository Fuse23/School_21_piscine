/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:43:24 by falarm            #+#    #+#             */
/*   Updated: 2021/07/22 14:10:20 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
