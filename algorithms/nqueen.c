#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int** initBoard(int n){
    int** board = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        board[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }

    return board;
}

void printBoard(int **b, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %2d ", b[i][j]);
        } 
        printf("\n");
    }   

}

void freeBoard(int **b, int n){
    for(int i = 0; i < n; i++){
        free(b[i]);
    }
    free(b);
}

bool isSafe(int** b, int row, int col, int n){
    int i, j;

    /*  Check left side of current row  */
    for(i = 0; i < col; i++){
        if(b[row][i]){
            return false;
        }
    }

  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (b[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (b[i][j]) 
            return false; 
  
    return true; 

}

bool placeQueens(int **b, int n, int col){

    /* When each column has a queens placed in, then it's done  */
    if(col >= n){
        return true;
    }

    /*  Check each row for the current column and tries to place a queen    */
    for(int i = 0; i < n; i++){

        /*  If this square is not under attack, place queen on it*/
        if(isSafe(b, i, col, n)){
            
            b[i][col] = 1;
            
            /*  Keeps placing queens on next rows   */
            if(placeQueens(b, n, col +1)){
                return true;
            }
            
            /*  If it hits a dead end, backtracks to previous state */
            b[i][col] = 0;
        }

    }

    return false;
}



void nQueenProblem(int** b, int n){

    if(placeQueens(b, n, 0)){
        printBoard(b, n);
        return;
    }

    printf("Could not place queens!");

}

int main(void){

    int n = 4;
    int** board = initBoard(n);

    nQueenProblem(board, n);

    freeBoard(board, n);

    return 0;
}