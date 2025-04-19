/******************************************************************************

Name: Junwei Chen, Date: 9/29/24, Course: 2107, Lab 05 2D Arrays

This program allows users to create and manipulate a 2D array.
It computes and displays the maximum value in the array, 
the sum of each row, and the sum of each column. It also checks whether the array is a square
and finally prints the entire array.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int max(int** arr, int rows, int cols);
int rowSum(int** arr, int rows, int cols);
int columnSum(int** arr, int col, int rows);
void isSquare(int rows, int cols);
void displayOutputs(int** arr, int rows, int cols);

int main()
{
    int rows, cols;
    
    puts("Lets create a 2Dim array!");
    puts("");
    printf("    How many rows? ");
    scanf("%d", &rows);
    printf("    How many columns? ");
    scanf("%d", &cols);
    puts("");
    
    int** TwoDarray = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        TwoDarray[i] = (int*)malloc(cols * sizeof(int));
    }
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("    Enter value for [%d][%d]: ", i, j);
            scanf("%d", &TwoDarray[i][j]);
        }
    }
    puts("");
    printf("The maximum value in this 2D array is: %d\n", max(TwoDarray, rows, cols));
    puts("");
    for (int i = 0; i < rows; i++) {
        printf("Sum of row %d: %d\n", i+1, rowSum(TwoDarray,i, cols));
    }
    puts("");
    for (int j = 0; j < cols; j++) {
        printf("Sum of column %d: %d\n", j+1, columnSum(TwoDarray, j, rows));
    }
    puts("");
    isSquare(rows,cols);
    puts("");
    puts("Here is your 2Dim array:");
    displayOutputs(TwoDarray, rows, cols);
    
    for (int i = 0; i < rows; i++) {
        free(TwoDarray[i]);
    }
    free(TwoDarray);
    
    

    return 0;
}

// returns the maximum value in the 2d array.
int max(int** arr,int rows,int cols) {
    int max = arr[0][0];
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

// returns the sum of the elements in Row x of the 2d array.
int rowSum(int** arr, int row, int cols) {
    int sum = 0; 
    for (int j = 0; j < cols; j++) {
        sum += arr[row][j]; 
    }
    return sum; 
}

// returns the sum of the elements in Column x of the 2d array.
int columnSum(int** arr, int col, int rows) {
    int sum = 0; 
    for (int i = 0; i < rows; i++) {
        sum += arr[i][col]; 
    }
    return sum; 
}

// checks if the array is square.
void isSquare(int rows, int cols) {
    if (rows != cols) {
        puts("This is not a square array.");
    } else {
        puts("This is a square array.");
    }
}

// displays the 2D array elements.
void displayOutputs(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("["); 
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]); 
            if (j < cols - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}