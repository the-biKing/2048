#include"matrixManipulation.h"
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

int i, j;

int merge;

int movespace;

void moveUp(int matrix[4][4]){
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j]!=0) {
                matrix[i][j] *= 2;
                matrix[i + 1][j] = 0;
                merge++;
                movespace++;
            }
        }
        int count_v = 0;//zero not++ to fill matrix upward 
        for (i = 0; i < 4; i++) {
            if (matrix[i][j] != 0) {
                matrix[count_v][j] = matrix[i][j];
                if (count_v != i) {
                    matrix[i][j] = 0;
                    movespace++;
                }
                count_v++;
            }
        }
    }
}
void moveRight(int matrix[4][4]){
    for (i = 0; i < 4; i++) {
        for (j = 3; j >0; j--) {
            if (matrix[i][j] == matrix[i][j-1] && matrix[i][j] != 0) {
                matrix[i][j] *= 2;
                matrix[i][j-1] = 0;
                merge++;
                movespace++;
            }
        }
        int count_h = 3;//zero not-- to fill matrix rightward 
        for (j = 3; j >=0; j--) {
            if (matrix[i][j] != 0) {
                matrix[i][count_h] = matrix[i][j];
                if (count_h != j) {
                    matrix[i][j] = 0;
                    movespace++;
                }
                count_h--;
            }
        }
    }
}
void moveLeft(int matrix[4][4]){
    for (i = 0; i < 4; i++) {
        for (j = 0; j <3; j++) {
            if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] != 0) {
                matrix[i][j] *= 2;
                matrix[i][j + 1] = 0;
                merge++;
                movespace++;
            }
        }
        int count_h = 0;//zero not++ to fill matrix leftward 
        for (j = 0; j <4; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][count_h] = matrix[i][j];
                if (count_h != j) {
                    matrix[i][j] = 0;
                    movespace++;
                }
                count_h++;
            }
        }
    }
}
void moveDown(int matrix[4][4]){
    for (j = 0; j < 4; j++) {
        for (i = 3; i >0; i--) {
            if (matrix[i][j] == matrix[i - 1][j] && matrix[i][j] != 0) {
                matrix[i][j] *= 2;
                matrix[i - 1][j] = 0;
                merge++;
                movespace++;
            }
        }
        int count_v = 3;//zero not-- to fill matrix downward 
        for (i = 3; i >=0; i--) {
            if (matrix[i][j] != 0) {
                matrix[count_v][j] = matrix[i][j];
                if (count_v != i) {
                    matrix[i][j] = 0;
                    movespace++;
                }
                count_v--;
            }
        }
    }
}
void addNumber(int matrix[4][4],int *x,int *y){
    int maxNumber=2;
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            if (matrix[i][j] >=maxNumber) {
                maxNumber = matrix[i][j];
            }
        }
    }
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
        int two_four=rand()%10;
        int maxlog = log2(maxNumber) - 1;
        if(matrix[i][j]==0){
            if(two_four<=9-(maxlog/2)){
                matrix[i][j]=2;
                *x = i;
                *y = j;
                keepFinding=false;
            }
            else{
                matrix[i][j]=4;
                *x = i;
                *y = j;
                keepFinding=false;
            }
        }

    }
    return;
}