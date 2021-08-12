#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_rash.h"

int findEmptyY(int board[4][4])
{
        int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (board[i][j] == 0)
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}

int findEmptyX(int board[4][4])
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (board[i][j] == 0)
                return (i);
            j++;
        }
        i++;
    }
    return (-1);
}

//How many buildings are visible
int visibleX(int *bilding)
{
    int max;
    int v;
    int i;

    v = 1;
    i = 1;
    max = bilding[0];
    while (i < 4)
    {
        if (max < bilding[i])
        {
            max = bilding[i];
            v++;
        }
        i++;
    }
    return (v);
}

int visibleY(int bilding[4][4], int j)
{
    int max;
    int v;
    int i;

    v = 1;
    i = 1;
    max = bilding[0][j];
    while (i < 4)
    {
        if (max < bilding[i][j])
        {
            max = bilding[i][j];
            v++;
        }
        i++;
    }
    return (v);
}

int validate(int number, int *index, int board[4][4], int *conditions)
{
    int i;

    i = 0;
    //Check rows
    while (i < 4)
    {
        if (board[i][index[1]] == number && i != index[0])
            return (0);
        i++;
    }
    i = 0;
    //Check cols
    while (i < 4)
    {
        if (board[index[0]][i] == number && i != index[1])
            return (0);
        i++;
    }
    i = 0;
    //Chech visible bilding from up
    if (conditions[index[1]] < visibleY(board, index[1]))
    {
        //printf("Up %d\n", visibleY(board, index[1]));
        return (0);
    }
    //Chech visible bilding from down
    if (conditions[index[1] + 4] < visibleY(board, index[1]))
    {
        //printf("Down %d\n", visibleY(board, index[1]));
        return (0);
    }
    //Chech visible bilding from left
    if (conditions[index[0] + 8] < visibleX(board[index[0]]))
    {
        //printf("Left %d\n", visibleY(board, index[1]));
        return (0);
    }
    //Chech visible bilding from right
    if (conditions[index[0] + 12] < visibleX(board[index[0]]))
    {
        //printf("Right %d\n", visibleY(board, index[1]));
        return (0);
    }
    return(1);
}

int solve(int *conditions, int board[4][4])
{
    int index[2];  //index where put bilding
    int isValid; 
    int i;

    i = 1;
    index[0] = findEmptyX(board);
    index[1] = findEmptyY(board);
    if (index[0] == -1 && index[1] == -1)
        return (0);
    //printf("Index %d\n", index[0]);
    //printf("Index %d\n", index[1]);
    while (i < 5)
    {
        isValid = validate(i, index, board, conditions);
        //printf("Itera %d\n", i);
        if (isValid)
        {
            board[index[0]][index[1]] = i;
            //printf("Bilding %d\n", i);
            if (solve(conditions, board))
            {
                print(board);
                return (1);
            }
            board[index[0]][index[1]] = 0;
        }
        i++;
    }
    print(board);
    return (0);
}