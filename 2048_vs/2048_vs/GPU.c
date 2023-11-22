#define _CRT_SECURE_NO_WARNINGS
#include "GPU.h"
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char n0_0[20] = "################";
char n0_1[20] = "#####      #####";
char n0_2[20] = "###   ####   ###";
char n0_3[20] = "###  ######  ###";
char n0_4[20] = "###   ####   ###";
char n0_5[20] = "#####      #####";
char n0_6[20] = "################";
char *n0[7] = {n0_0, n0_1, n0_2, n0_3, n0_4, n0_5, n0_6};
char n1_0[20] = "################";
char n1_1[20] = "#####     ######";
char n1_2[20] = "######    ######";
char n1_3[20] = "######    ######";
char n1_4[20] = "######    ######";
char n1_5[20] = "#####      #####";
char n1_6[20] = "################";
char *n1[7] = {n1_0, n1_1, n1_2, n1_3, n1_4, n1_5, n1_6};
char n2_0[20] = "################";
char n2_1[20] = "####        ####";
char n2_2[20] = "########     ###";
char n2_3[20] = "#########   ####";
char n2_4[20] = "#######    #####";
char n2_5[20] = "####         ###";
char n2_6[20] = "################";
char *n2[7] = {n2_0, n2_1, n2_2, n2_3, n2_4, n2_5, n2_6};
char n3_0[20] = "################";
char n3_1[20] = "####        ####";
char n3_2[20] = "########    ####";
char n3_3[20] = "####      ######";
char n3_4[20] = "########    ####";
char n3_5[20] = "####        ####";
char n3_6[20] = "################";
char *n3[7] = {n3_0, n3_1, n3_2, n3_3, n3_4, n3_5, n3_6};
char n4_0[20] = "################";
char n4_1[20] = "#######     ####";
char n4_2[20] = "######  #   ####";
char n4_3[20] = "####  ###   ####";
char n4_4[20] = "###           ##";
char n4_5[20] = "#########   ####";
char n4_6[20] = "################";
char *n4[7] = {n4_0, n4_1, n4_2, n4_3, n4_4, n4_5, n4_6};
char n5_0[20] = "################";
char n5_1[20] = "####         ###";
char n5_2[20] = "####   #########";
char n5_3[20] = "####        ####";
char n5_4[20] = "#########    ###";
char n5_5[20] = "####        ####";
char n5_6[20] = "################";
char *n5[7] = {n5_0, n5_1, n5_2, n5_3, n5_4, n5_5, n5_6};
char n6_0[20] = "################";
char n6_1[20] = "#####      #####";
char n6_2[20] = "####    ########";
char n6_3[20] = "###        #####";
char n6_4[20] = "###   ###   ####";
char n6_5[20] = "####       #####";
char n6_6[20] = "################";
char *n6[7] = {n6_0, n6_1, n6_2, n6_3, n6_4, n6_5, n6_6};
char n7_0[20] = "################";
char n7_1[20] = "####         ###";
char n7_2[20] = "#########    ###";
char n7_3[20] = "########    ####";
char n7_4[20] = "#######    #####";
char n7_5[20] = "######    ######";
char n7_6[20] = "################";
char *n7[7] = {n7_0, n7_1, n7_2, n7_3, n7_4, n7_5, n7_6};
char n8_0[20] = "################";
char n8_1[20] = "######    ######";
char n8_2[20] = "####   ##   ####";
char n8_3[20] = "######    ######";
char n8_4[20] = "####  ####  ####";
char n8_5[20] = "#####      #####";
char n8_6[20] = "################";
char *n8[7] = {n8_0, n8_1, n8_2, n8_3, n8_4, n8_5, n8_6};
char n9_0[20] = "################";
char n9_1[20] = "#####      #####";
char n9_2[20] = "###   ####  ####";
char n9_3[20] = "####         ###";
char n9_4[20] = "#########    ###";
char n9_5[20] = "####       #####";
char n9_6[20] = "################";
char *n9[7] = {n9_0, n9_1, n9_2, n9_3, n9_4, n9_5, n9_6};

char **number[10] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};

static void gotoxy(int x, int y);

void display(int matrix[4][4])
{
    system("cls");
    int j = 0;
    while (j <= 84)
    {
        for (int i = 0; i < 32; i++)
        {
            gotoxy(j, i);
            printf("|");
        }
        j = j + 21;
    }
    j = 0;
    while (j < 39)
    {
        for (int i = 1; i < 84; i++)
        {
            gotoxy(i, j);
            if (i % 21 == 0)
            {
                continue;
            }
            printf("-");
        }
        j = j + 8;
    }
    for (int v = 0; v < 4; v++)
    {
        for (int h = 0; h < 4; h++)
        {
            if (matrix[v][h] == 0)
            {
                continue;
            }
            int Number = log2(matrix[v][h]) - 1;
            for (int i = 0; i < 7; i++)
            {
                gotoxy(3+21*h, (i + 1)+8*v);
                printf("%s", number[Number][i]);
            }
        }
    }

    gotoxy(0, 33);
    return 0;
}
void p11(int x)
{
    if (x == 0)
    {
        return;
    }
    int Number = log2(x) - 1;
    for (int i = 0; i < 7; i++)
    {
        gotoxy(3, i + 1);
        printf("%s", number[Number][i]);
    }
}

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}