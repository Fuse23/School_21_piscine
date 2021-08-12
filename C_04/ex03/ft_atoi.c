/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:01:20 by falarm            #+#    #+#             */
/*   Updated: 2021/07/27 21:48:42 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_space(char t)
{
	if (t == '\n' || t == '\t' || t == '\r'
		|| t == '\f' || t == '\v' || t == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] != '\0'
		&& (str[i] == '-' || str[i] == '+' || ft_is_space(str[i])))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] != '-' && str[i] != '+' && !ft_is_space(str[i]))
		if (str[i] < '0' || str[i] > '9')
			return (0);
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * sign);
}
int 	main()
{
	char str[] = "---   + -123e456sfdf";
	ft_atoi(str);
	return 0;
}