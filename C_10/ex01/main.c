/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:38:39 by falarm            #+#    #+#             */
/*   Updated: 2021/08/03 12:28:41 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	only_cat(void)
{
	ssize_t	f;
	char	buf;

	f = read(1, &buf, 1);
	while (f)
	{
		write(1, &buf, 1);
		f = read(1, &buf, 1);
	}
}

void	ft_errors(char *p, char *f)
{
	ft_putstr(basename(p));
	write(2, ": ", 2);
	ft_putstr(f);
	write(2, ": ", 2);
	ft_putstr(strerror(errno));
	write(2, "\n", 1);
}

void	cat_fs(char *wread, char *pname)
{
	char	t;
	int		f;
	int		r;

	f = open(wread, O_RDONLY, 0);
	if (f < 0)
		ft_errors(pname, wread);
	else
	{
		r = read(f, &t, 1);
		if (r < 0)
			ft_errors(pname, wread);
		while (r > 0)
		{
			write(1, &t, 1);
			r = read(f, &t, 1);
		}
		close(f);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		only_cat();
	else
	{
		while (i < argc)
		{
			cat_fs(argv[i], argv[0]);
			i++;
		}
	}
	return (0);
}
