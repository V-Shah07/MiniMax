#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include "Header.h"

#define Xscore 10
#define Oscore -10
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int position2 = 0;
int calls2 = 0;
char board2[9];
int determineMoveReal(int emptyPos, bool player, int* depth, int alpha, int beta)
{
    ++calls2;


    int returnValue;
    char win = isWin(board2);
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
        if (board2[i] != '_')
        {
            continue;
        }
        else
        {
            if (alpha >= beta)
            {
                //prune
                break;
            }
            board2[i] = sym[player];

            ans = determineMoveReal(emptyPos - 1, !player, depth, alpha, beta);

            board2[i] = '_';

            if ((state[player] == maximizing) && (ans > maxScore))
            {
                posFinal = i;
                maxScore = ans;
            }
            if ((state[player] == minimizing) && (ans < maxScore))
            {
                posFinal = i;
                maxScore = ans;
            }            
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
            (state[player] == maximizing) ? (alpha = max(alpha, ans)) : (beta = min(beta, ans));

        }
        *depth = curIterations;
    }

    *depth = leastIterations + 1;
    position2 = posFinal;
    return maxScore;

}

int determineMoveFast(char* field, bool player, int* numCalls)
{
    int numEmpty = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (field[i] == '_')
        {
            ++numEmpty;
        }
    }
    memcpy(board2, field, strlen(field));
    int depth = 0;
    determineMoveReal(numEmpty, player, &depth, -1 * INT_MAX, INT_MAX);
    *numCalls = calls2;
    return position2;

}
