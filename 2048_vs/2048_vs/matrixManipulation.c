#include"matrixManipulation.h"
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

void moveUp(int matrix[4][4]){

}
void moveRight(int matrix[4][4]){

}
void moveLeft(int matrix[4][4]){

}
void moveDown(int matrix[4][4]){

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