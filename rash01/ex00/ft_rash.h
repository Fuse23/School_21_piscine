#ifndef FT_RASH_H
# define FT_RASH_H

# include <unistd.h>
# include <stdlib.h>

// int **create_board();
// int ft_strlen(char *str);
// int *create_condition(char **cond);
int findEmptyY(int board[4][4]);
int findEmptyX(int board[4][4]);
int visibleX(int *bilding);
int visibleY(int bilding[4][4], int j);
int validate(int number, int *index, int board[4][4], int *conditions);
int solve(int *conditions, int board[4][4]);
void    print(int board[4][4]);

#endif