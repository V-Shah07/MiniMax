#include <stdio.h>



void printBoard(char* board)
{
	for (int x = 0; x < 9; ++x)
	{
		if ((x % 3) == 0)
		{
			printf("\n");
		}
		printf("%c ", board[x]);
	}
	printf("\n");
}

char isWin(char* board)
{
	short winCases[8][3] =
	{
		//Horiz:
		{0,1,2},
		{3,4,5},
		{6,7,8},
		//Vertic:
		{0,3,6},
		{1,4,7},
		{2,5,8},
		//Diag:
		{0,4,8},
		{2,4,6}
	};
	int numFilled = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (( (board[winCases[i][0]] == board[winCases[i][1]]) && (board[winCases[i][0]] == board[winCases[i][2]]) ) && (board[winCases[i][0]] != '_'))
		{
			;
			return board[winCases[i][0]];
		}
		
	}

	for (int i = 0; i < 9; ++i)
	{
		if (board[i] != '_')
		{
			++numFilled;
		}
	}
	if (numFilled == 9)
	{
		return 't';
	}
	return 'n';
}