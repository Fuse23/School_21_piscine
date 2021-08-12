#include <unistd.h>
#include <stdlib.h>

// int **create_board()
// {
//     int **board;
//     int i;
//     int j;

//     i = 0;
//     *board = malloc(4 * sizeof(int));
//     if (*board == NULL)
//         return (NULL);
//     while (i < 4)
//     {
//         board[i] = malloc(4 * sizeof(int));
//         if (board[i] == NULL)
//             return (NULL);
//         i++;
//     }
//     i = 0;
//     while (i < 4)
//     {
//         j = 0;
//         while (j < 4)
//         {
//             board[i][j] = 0;
//             j++;
//         }
//         i++;
//     }
//     return (board);
// }

// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         i++;
//     return (i);
// }

// int *create_condition(char **cond)
// {
//     int *condition;
//     int i;

//     i = 0;
//     condition = malloc(ft_strlen(cond[1]) * sizeof(int));
//     if (condition == NULL)
//         return (NULL);
//     while (cond[1][i])
//     {
//         condition[i] = cond[1][i] - 48;
//         i++;
//     }
//     return (condition);
// }

void    print(int board[4][4])
{
    int     i;
    int     j;
    char    t;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            t = board[i][j] + 48;
            write(1, &t, 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}