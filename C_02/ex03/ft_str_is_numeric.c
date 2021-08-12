/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:05:40 by falarm            #+#    #+#             */
/*   Updated: 2021/07/24 16:22:38 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	t;

	i = 0;
	t = 1;
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || (str[i] > '9'))
		{
			t = 0;
			return (t);
		}
		i++;
	}
	return (t);
}
