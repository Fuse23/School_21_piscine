#include "ft_rash.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int board[4][4];
    int condition[16];
    int i;
    int j;

    if (argc > 2)
        return (0);
    // board = create_board();
    // if (board == NULL)
        // return (0);
    // condition = create_condition(argv);
    // if (condition == NULL)
    //     return (0);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
    //print(board);
    i = 0;
    j = 0;
    while (argv[1][i])
    {
        if (argv[1][i] != ' ')
        {
            condition[j] = argv[1][i] - 48;
            j++;
        }
        i++;
    }
    i = 0;
    // while (i < 16)
    // {
    //     printf("%d\t", condition[i]);
    //     i++;
    // }
    solve(condition, board);
    //free(board);
    //free(condition);
    return (0);
}