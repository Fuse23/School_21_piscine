/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:58:08 by falarm            #+#    #+#             */
/*   Updated: 2021/08/02 15:58:35 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	t;
	ssize_t	i;
	int		f;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 2)
	{
		f = open(argv[1], O_RDONLY, 0);
		if (f < 0)
			write(2, "Cannot read file.\n", 18);
		i = read(f, &t, 1);
		if (i < 0)
			write(2, "Cannot read file.\n", 18);
		while (i > 0)
		{
			write(1, &t, 1);
			i = read(f, &t, 1);
		}	
		close(f);
	}
	return (0);
}
