#include <stdio.h>
#include <stdbool.h>
#include "matrixManipulation.h"

char checkState(int matrix[4][4]);

int main(void)
{
	int board[4][4],c;
	bool gameContinue = true;
	char playerInput;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}
	while (gameContinue)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		scanf("%c", &playerInput);
		while ((c = getchar()) != '\n' && c != EOF);
		if (playerInput == 'w')
		{
			moveUp(board[4][4]);
		}
		else if (playerInput == 'a')
		{
			moveLeft(board[4][4]);
		}
		else if (playerInput == 's')
		{
			moveDown(board[4][4]);
		}
		else if (playerInput == 'd')
		{
			moveRight(board[4][4]);
		}
		else
		{
			printf("Invalid input");
		}
		addNumber(board[4][4]);
		if (checkState != 'c')
		{
			gameContinue = false;
		}
	}
	if (checkState == 'w')
	{
		printf("win");
	}
	if (checkState == 'l')
	{
		printf("lose");
	}

	return 0;
}

char checkState(int matrix[4][4])
{
}