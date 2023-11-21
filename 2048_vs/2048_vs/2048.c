#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "matrixManipulation.h"

char checkState(int matrix[4][4]);



int main(void)
{
	//����move��
	/*
	int M[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			M[i][j] = 2;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	moveUp(M);
	moveDown(M);
	moveRight(M);
	moveLeft(M);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}*/

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
		//while ((c = getchar()) != '\n' && c != EOF);
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
	return 'c';
}