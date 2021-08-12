/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:59:49 by falarm            #+#    #+#             */
/*   Updated: 2021/07/29 19:20:57 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	len(int size, char **strs, char *sep)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
		k += ft_strlen(strs[i++]);
	k += ft_strlen(sep) * (size - 1);
	return (k + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*s;
	int		j;
	int		k;

	if (size < 1)
		return ("");
	s = malloc(len(size, strs, sep));
	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && (size - i != 1))
			s[k++] = sep[j++];
		i++;
	}
	s[k] = '\0';
	return (s);
}
