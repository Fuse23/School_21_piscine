/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:11:48 by falarm            #+#    #+#             */
/*   Updated: 2021/07/22 14:42:35 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	d;
	int	m;

	d = a / b;
	m = a % b;
	*div = d;
	*mod = m;
}
