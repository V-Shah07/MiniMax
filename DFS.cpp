#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include "Header.h"

#define Xscore 10
#define Oscore -10


int position = 0;
int calls = 0;
char board[9];
int DFS(int emptyPos, bool player, int* depth)
{
    ++calls;


    int returnValue;
    char win = isWin(board);
    if (win == sym[player])
    {
        returnValue = score[player];


        *depth += 1;

        return returnValue;
    }
    else if (win == sym[!player])
    {
        returnValue = score[!player];
        *depth += 1;

        return returnValue;
    }
    if (win == 't')
    {
        returnValue = 0;

        *depth += 1;

        return returnValue;
    }
    


    int maxScore = score[player] * -10;


    int leastIterations = INT_MAX;
    int posFinal = -1;

    int ans;
    int curIterations = *depth;
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != '_')
        {
            continue;
        }
        else
        {
            board[i] = sym[player];

            ans = DFS(emptyPos - 1, !player, depth);

            board[i] = '_';

            if ((state[player] == maximizing) && (ans > maxScore))
            {
                posFinal = i;
                maxScore = ans;
            }
            //if ((sym[player] == 'x') && (ans > maxScore))
            //{
            //    posFinal = i;
            //    maxScore = ans;
            //}

            if ((state[player] == minimizing) && (ans < maxScore))
            {
                posFinal = i;
                maxScore = ans;
            }
            //else if ((sym[player] == 'o') && (ans < maxScore))
            //{
            //    posFinal = i;
            //    maxScore = ans;
            //}
            if ((state[player] == maximizing) && (ans >= maxScore) && (*depth < leastIterations))
            {
                leastIterations = *depth;
                posFinal = i;
            }
            else if ((state[player] == minimizing) && (ans <= maxScore) && (*depth < leastIterations))
            {
                leastIterations = *depth;
                posFinal = i;
            }

        }
        *depth = curIterations;
    }

    *depth = leastIterations + 1;
    position = posFinal;
    return maxScore;

}

int determineMoveSlow(char* field, bool player, int* numCalls)
{
    int numEmpty = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (field[i] == '_')
        {
            ++numEmpty;
        }
    }
    memcpy(board, field, strlen(field));
    int depth = 0;
    DFS(numEmpty, player, &depth);
    *numCalls = calls;
    return position;

}
