#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "matrixManipulation.h"
#include "GPU.h"

char checkState(int matrix[4][4]);

int main(void)
{
	int board[4][4], c;
	bool gameContinue = true;
	char playerInput;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}
	addNumber(board);
	while (gameContinue)
	{
		system("cls");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		scanf("%c", &playerInput);
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (playerInput == 'w')
		{
			moveUp(board);
		}
		else if (playerInput == 'a')
		{
			moveLeft(board);
		}
		else if (playerInput == 's')
		{
			moveDown(board);
		}
		else if (playerInput == 'd')
		{
			moveRight(board);
		}
		else
		{
			printf("Invalid input");
		}
		addNumber(board);
		if (checkState(board) != 'c')
		{
			gameContinue = false;
		}
	}
	if (checkState(board) == 'w')
	{
		printf("win");
	}
	if (checkState(board) == 'l')
	{
		printf("lose");
	}

	return 0;
}

char checkState(int matrix[4][4])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 0 || matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i][j - 1] || matrix[i][j] == matrix[i + 1] || matrix[i][j] == matrix[i - 1][j])
			{
				return 'c'; // c=game continue
				break;
			}
			else if (matrix[i][j] == 2048)
			{
				return 'w'; // w=win (only when reach 2048)
			}
		}
	}
	return 'l';
}