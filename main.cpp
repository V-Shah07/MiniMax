#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
#pragma warning(disable:4996)
void clearBoard(char* board)
{
	for (int i = 0; i < 9; ++i)
	{
		board[i] = '_';
	}
}
void userPlay(char* board)
{
	char choice;

	bool user, comp;
	int numCalls = 0;
	int numCallsSlow = 0;
	bool player;

	printf("Do you want to go first(y for yes and n for no): ");
	scanf("%c", &choice);


	if (choice == 'y')
	{
		user = 0;
		player = user;
	}
	else
	{
		user = 1;
		player = !user;
	}
	comp = !user;


	int pos;

	char winner;
	for (int i = 0; i < 9;)
	{

		if (player == user)
		{
			printf("What position would you like to place a letter in: ");
			scanf("%d", &pos);
			pos -= 1;
			if(pos < 0 || pos > 9)
			{
				printf("Out of range.\n");
				continue;;
			}
			if (board[pos] != '_')
			{
				printf("That is taken.\n");
				continue;
			}
		}
		else
		{
			pos = determineMoveFast(board, player, &numCalls);
			determineMoveSlow(board, player, &numCallsSlow);
		}
		board[pos] = sym[player];

		printBoard(board);
		if ((winner = isWin(board)) != 'n')
		{
			if(winner == 't')
			{
				printf("It is a tie!!\n\n");
			}
			else
			{
				printf("\n\n%c WINS!!", winner);
			}
			break;
		}
		player = !player;
		++i;
	}
	printf("\nNumber of recursive iterations in functions for DFS without Alpha-Beta Pruning(ABP) and with ABP:\n");
	printf("DFS\t\tDFS with ABP\n");
	printf("%d\t\t%d\n\n", numCallsSlow, numCalls);
	printf("There were %d times as many recursive function iterations without ABP compared to with ABP!\n", numCallsSlow/numCalls);

}
char autoPlay(char* board)
{
	srand((unsigned int)time(NULL));
	bool algorithm, random;
	bool player;
	int numCalls;
	//should random player go first
	bool choice = rand() % 2;

	if (choice)
	{
		random = 0;
		player = random;
	}
	else
	{
		random = 1;
		player = !random;
	}
	algorithm = !random;

	int pos;
	char winner;
	for (int i = 0; i < 9;)
	{

		if (player == random)
		{
			pos = rand() % 9;
			while (board[pos] != '_')
			{
				pos = rand() % 9;
			}
		}
		else
		{
			pos = determineMoveFast(board, sym[player], &numCalls);
		}
		board[pos] = sym[player];

		//printBoard(board);
		if ((winner = isWin(board)) != 'n')
		{
			break;
		}
		player = !player;
		++i;
	}

	if (sym[algorithm] == winner)
	{
		return 1;
	}
	else if (sym[random] == winner)
	{
		return -1;
	}
	
	return 0;
}
void testing(char* board)
{
	int wins = 0, losses = 0, ties = 0;
	int numGames;
	printf("How many games do you want to run: ");
	scanf("%d", &numGames);
	for (int i = 0; i < numGames; ++i)
	{
		switch (autoPlay(board))
		{
		case 1:
			wins++;
			break;
		case 0:
			ties++;
			break;
		case -1:
			losses++;
			break;
		}
		clearBoard(board);
	}
	printf("%d\t%d\t%d\n", wins, ties, losses);
	printf("%lf%% wins, %lf%% ties, %lf%% losses", (double)wins / numGames * 100.0, (double)ties / numGames * 100.0, (double)losses / numGames * 100.0);

}

int main()
{

	char board[9] = {'_', '_', '_', '_', '_', '_','_', '_', '_'};

	char choice;
	printf("do you want to run multiple tests or play a game?(y for testing and n for a game): ");
	choice = getchar();
	getchar();
	if (choice == 'y')
		testing(board);
	else
		userPlay(board);
}