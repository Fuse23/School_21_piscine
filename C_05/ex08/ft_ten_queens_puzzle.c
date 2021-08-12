/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:01:00 by falarm            #+#    #+#             */
/*   Updated: 2021/07/27 21:29:32 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	setQueen(int i, int j, int board[][10])
{
	int	x;

	x = 0;
	while (x < 10)
	{
		board[x][j] += 1;
		board[i][x] += 1;
		if ((i + j - x >= 0) && (i + j - x < 10))
			board[i + j - x][x] += 1;
		if ((i - j + x >= 0) && (i - j + x < 10))
			board[i - j + x][x] += 1;
		x++;
	}
	board[i][j] = -1;
}

void	removeQueen(int i, int j, int board[][10])
{
	int	x;

	x = 0;
	while (x < 10)
	{
		board[x][j] -= 1;
		board[i][x] -= 1;
		if ((i + j - x >= 0) && (i + j - x < 10))
			board[i + j - x][x] -= 1;
		if ((i - j + x >= 0) && (i - j + x < 10))
			board[i - j + x][x] -= 1;
		x++;
	}
	board[i][j] = 0;
}

void	printPosition(int board[][10])
{
	int		i;
	int		j;
	char	t;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == -1)
			{
				t = j + '0';
				write(1, &t, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	solve(int i, int board[][10], int *n)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		if (board[i][j] == 0)
		{
			setQueen(i, j, board);
			if (i == 9)
			{
				printPosition(board);
				*n = *n + 1;
			}
			else
				solve((i + 1), board, n);
			removeQueen(i, j, board);
		}
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	solve(0, board, &n);
	return (n);
}
