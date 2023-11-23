#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<conio.h>
#include<Windows.h>
#include "matrixManipulation.h"
#include "GPU.h"

char checkState(int matrix[4][4]);

extern int merge;
extern int movespace;
char state;

int main(void)
{
	int board[4][4], c;
	int count = 0;
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
		while (1) {
			if (_kbhit()) {
				int key = _getch(); // Get the key code
				if (key == 224) { // Check for arrow keys
					key = _getch(); // Second _getch() to capture arrow key codes
					switch (key) {
					case 72: // Up arrow
						playerInput = 'w';
						break;
					case 75: // Left arrow
						playerInput = 'a';
						break;
					case 77: // Right arrow
						playerInput = 'd';
						break;
					case 80: // Down arrow
						playerInput = 's';
						break;
					default:
						break;
					}
					break; // Break out of the while loop after processing key input
				}
			}
		}
		movespace = 0;
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
		if (movespace != 0) {
			addNumber(board);
		}
		state=checkState(board);
		if (state != 'c')
		{
			gameContinue = false;
		}
	}
	if (state == 'w')
	{
		display(board);
		printf("win");
	}
	if (state == 'l')
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

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i + 1][j])
			{
				return 'c'; // c=game continue
				break;
			}
		}
	}
	return 'l'; // l=lose
}