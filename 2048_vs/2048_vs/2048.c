#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#include "matrixManipulation.h"
#include "GPU.h"
#pragma comment(lib,"winmm.lib")
char checkState(int matrix[4][4]);
void colorPrint(const char* text, int red, int green, int blue);
void goto_xy(int x, int y);

extern int merge;
extern int movespace;
char state;

int main(void)
{
	int maxNumber = 2;
	int horizontalNew, verticleNew;
	int board[4][4];
	int count = 0,score=0;
	bool gameContinue = true;
	bool add = true;
	bool playDin = true;
	char playerInput;
	int trickORtreat;
START:
	gameContinue = true;
	add = true;
	playDin = true;
	count = 0;
	score = 0;
	maxNumber = 2;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}
	addNumber(board,&horizontalNew,&verticleNew);
	while (gameContinue)
	{
		system("cls");
		display(board,horizontalNew,verticleNew,add);
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
				else {
					playerInput = 't';
					break;
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
		else if (playerInput == 't')
		{
			srand(time(0));
			trickORtreat = rand() % 10;
			if (trickORtreat>6) {
				int max = board[0][0];
				int maxI = 0, maxJ = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (board[i][j] > max) {
							max = board[i][j];
							maxI = i;
							maxJ = j;
						}
					}
				}
				board[maxI][maxJ] *= 2;
				colorPrint("T", 240, 30, 30);
				colorPrint("R", 240, 130, 30);
				colorPrint("E", 240, 240, 30);
				colorPrint("A", 30, 240, 30);
				colorPrint("T", 240, 30, 240);
				Sleep(1000);
			}
			else {
				int max = board[0][0];
				int maxI = 0, maxJ = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (board[i][j] > max) {
							max = board[i][j];
							maxI = i;
							maxJ = j;
						}
					}
				}
				board[maxI][maxJ] = 0;
				printf("Trick");
				Sleep(1000);
			}
		}
		else
		{
			printf("Invalid input");
		}
		if (movespace != 0) {
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < 4;j++) {
					if (board[i][j] > maxNumber) {
						maxNumber = board[i][j];
						PlaySound(TEXT("levelUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
						playDin = false;
					}
					
				}
			}
			if (playDin&&merge>0) {
				PlaySound(TEXT("din.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			playDin = true;
			
			addNumber(board,&horizontalNew,&verticleNew);
			add = true;
		}
		else {
			PlaySound(TEXT("accessDenied.wav"), NULL, SND_FILENAME | SND_ASYNC);
			int j = 0;
			while (j <= 84)
			{
				for (int i = 0; i < 32; i++)
				{
					goto_xy(j, i);
					colorPrint("|",240,30,30);
				}
				j = j + 21;
			}
			j = 0;
			while (j < 39)
			{
				for (int i = 1; i < 84; i++)
				{
					goto_xy(i, j);
					if (i % 21 == 0)
					{
						continue;
					}
					colorPrint("-", 240, 30, 30);
				}
				j = j + 8;
			}
			Sleep(200);
			j = 0;
			while (j <= 84)
			{
				for (int i = 0; i < 32; i++)
				{
					goto_xy(j, i);
					colorPrint("|", 240, 240, 240);
				}
				j = j + 21;
			}
			j = 0;
			while (j < 39)
			{
				for (int i = 1; i < 84; i++)
				{
					goto_xy(i, j);
					if (i % 21 == 0)
					{
						continue;
					}
					colorPrint("-", 240, 240, 240);
				}
				j = j + 8;
			}
			Sleep(100);
			j = 0;
			while (j <= 84)
			{
				for (int i = 0; i < 32; i++)
				{
					goto_xy(j, i);
					colorPrint("|", 240, 30, 30);
				}
				j = j + 21;
			}
			j = 0;
			while (j < 39)
			{
				for (int i = 1; i < 84; i++)
				{
					goto_xy(i, j);
					if (i % 21 == 0)
					{
						continue;
					}
					colorPrint("-", 240, 30, 30);
				}
				j = j + 8;
			}
			Sleep(200);
			add = false;
		}
		state=checkState(board);
		if (state != 'c')
		{
			gameContinue = false;
		}
	}
	if (state == 'w')
	{
		display(board,horizontalNew,verticleNew,false);
		printf("win");
	}
	if (state == 'l')
	{
		
		display(board,horizontalNew,verticleNew,false);
		printf("lose\n");
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				score = score + board[i][j];
			}
		}
		printf("your score: %d\n",score);
	}


	printf("Press any key to continue...\n");
	while (!_kbhit()) {}
	char keyNow;
	system("cls");
	printf("Press 'y' to play again or 'q' to quit\n");

	// Input handling
	while (1) {
		if (_kbhit()) {
			keyNow = _getch();
			if (keyNow == 'q') {
				exit(0);
			}
			else if (keyNow == 'y') {
				goto START;
			}
		}
	}

	//return 0;
}

char checkState(int matrix[4][4])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (matrix[i][j] == 2048)
			{
				return 'w'; // w = win (only when reach 2048)
				break;
			}
			else if (matrix[i][j] == 0)
			{
				return 'c'; // c = game continue
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
	if (matrix[3][3] == matrix[2][3] || matrix[3][3] == matrix[3][2])
	{
		return 'c'; // c=game continue
		break;
	}
	return 'l'; // l=lose
}
void colorPrint(const char* text, int red, int green, int blue)
{
	printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", red, green, blue, text);
}
void goto_xy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}