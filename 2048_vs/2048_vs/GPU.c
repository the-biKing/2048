#define _CRT_SECURE_NO_WARNINGS
#include"GPU.h"
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

static void gotoxy(int x, int y);

void display(int matrix[4][4]){
    

}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}