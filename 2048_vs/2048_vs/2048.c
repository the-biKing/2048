#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "matrixManipulation.h"
#include "GPU.h"

char checkState(int matrix[4][4]);

extern int merge;

int main(void)
{
	int board[4][4], c;
	int count=0;
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
		display(board);
		scanf("%c", &playerInput);
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (playerInput == 'w')
		{
			count = 0;
			merge = 0;
			while (merge == 0) {
				moveUp(board);
				count++;
				if (count == 3) {
					break;
				}
			}
		}
		else if (playerInput == 'a')
		{
			count = 0;
			merge = 0;
			while (merge == 0) {
				moveLeft(board);
				count++;
				if (count == 3) {
					break;
				}
			}
		}
		else if (playerInput == 's')
		{
			count = 0;
			merge = 0;
			while (merge == 0) {
				moveDown(board);
				count++;
				if (count == 3) {
					break;
				}
			}
		}
		else if (playerInput == 'd')
		{
			count = 0;
			merge = 0;
			while (merge == 0) {
				moveRight(board);
				count++;
				if (count == 3) {
					break;
				}
			}
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
		display(board);
		printf("win");
	}
	if (checkState(board) == 'l')
	{
		display(board);
		printf("lose");
	}

	return 0;
}

char checkState(int matrix[4][4])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (matrix[i][j] == 0)
			{
				return 'c'; // c = game continue
				break;
			}
			else if (matrix[i][j] == 2048)
			{
				return 'w'; // w = win (only when reach 2048)
				break;
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i + 1][j])
			{
				return 'c'; // c=game continue
				break;
			}
			else
			{
				return 'l'; // l=lose
				break;
			}
		}
	}
}