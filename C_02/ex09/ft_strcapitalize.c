/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:17:06 by falarm            #+#    #+#             */
/*   Updated: 2021/07/24 20:36:00 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char str)
{
	if ((str < 'A' || str > 'Z') && (str < 'a' || str > 'z'))
		if (str < '1' || str > '9')
			return (1);
	return (0);
}

void	first(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
}

int	num(char str)
{
	if (str >= '1' && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	t;
	int	n;

	i = 1;
	t = 0;
	n = 0;
	first(str);
	while (str[i] != '\0')
	{	
		if (str[i] >= 'a' && str[i] <= 'z' && t == 1 && n == 0)
			str[i] -= 32;
		if (str[i] >= 'A' && str[i] <= 'Z' && t == 0)
			str[i] += 32;
		t = check(str[i]);
		n = num(str[i]);
		i++;
	}
	return (str);
}
