#include"matrixManipulation.h"
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

int i, j;
void moveUp(int matrix[4][4]){
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            if (matrix[i][j] == matrix[i + 1][j]) {
                matrix[i][j] *= 2;
                matrix[i + 1][j] = 0;
            }
        }
        int countv = 0;//zero not++ to fill matrix upward 
        for (i = 0; i < 4; i++) {
            if (matrix[i][j] != 0) {
                matrix[countv][j] = matrix[i][j];
                if (countv != i) {
                    matrix[i][j] = 0;
                }
                countv++;
            }
        }
    }
}
void moveRight(int matrix[4][4]){
    for (i = 0; i < 4; i++) {
        for (j = 3; j >0; j--) {
            if (matrix[i][j] == matrix[i][j-1]) {
                matrix[i][j] *= 2;
                matrix[i][j-1] = 0;
            }
        }
        int counth = 3;//zero not-- to fill matrix rightward 
        for (j = 3; j >=0; j--) {
            if (matrix[i][j] != 0) {
                matrix[i][counth] = matrix[i][j];
                if (counth != j) {
                    matrix[i][j] = 0;
                }
                counth--;
            }
        }
    }
}
void moveLeft(int matrix[4][4]){
    for (i = 0; i < 4; i++) {
        for (j = 0; j <3; j++) {
            if (matrix[i][j] == matrix[i][j + 1]) {
                matrix[i][j] *= 2;
                matrix[i][j + 1] = 0;
            }
        }
        int counth = 0;//zero not++ to fill matrix leftward 
        for (j = 0; j <4; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][counth] = matrix[i][j];
                if (counth != j) {
                    matrix[i][j] = 0;
                }
                counth++;
            }
        }
    }
}
void moveDown(int matrix[4][4]){
    for (j = 0; j < 4; j++) {
        for (i = 3; i >0; i--) {
            if (matrix[i][j] == matrix[i - 1][j]) {
                matrix[i][j] *= 2;
                matrix[i - 1][j] = 0;
            }
        }
        int countv = 3;//zero not-- to fill matrix downward 
        for (i = 3; i >=0; i--) {
            if (matrix[i][j] != 0) {
                matrix[countv][j] = matrix[i][j];
                if (countv != i) {
                    matrix[i][j] = 0;
                }
                countv--;
            }
        }
    }
}
void addNumber(int matrix[4][4]){
    srand(time(NULL));
    bool keepFinding=true;
    int countZero=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                countZero++;
            }
        }
    }
    if(countZero==0){
        keepFinding=false;
    }
    while(keepFinding){
        int i=rand()%4;
        int j=rand()%4;
        int twoOrfour=rand()%10;
        if(matrix[i][j]==0){
            if(twoOrfour<=7){
                matrix[i][j]=2;
                keepFinding=false;
            }
            else{
                matrix[i][j]=4;
                keepFinding=false;
            }
        }

    }
    return;
}