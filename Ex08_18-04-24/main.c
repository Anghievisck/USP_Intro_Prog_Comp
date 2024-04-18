/*
    This is a C programm that receives a Matrix from the user, then it checks if it is symmetric
    then if it is, it do the difference between the highest row sum and the lowest column sum.
*/

#include <stdio.h>

int main(){
    // Creates some variables
    int matrixDegree, difference = 0, biggestRow = 0, smallestCol = 100000;

    // Gets the number of rows and columns
    scanf("%d", &matrixDegree);

    // Creates the matrix and a array for the sums
    int matrix[matrixDegree][matrixDegree], sums[matrixDegree];

    // Gets the matrix elements from the user
    for(int i = 0; i < matrixDegree; i++){
        for(int j = 0; j < matrixDegree; j++){
            scanf("%d", &matrix[i][j]);
        }

        // Sets the sums array to zero
        sums[i] = 0;
    }

    // Checks if the matrix is symmetric
    for(int i = 0; i < matrixDegree; i++){
        for(int j = 0; j < matrixDegree; j++){
            if(matrix[i][j] == matrix[j][i]){
            } else {
                printf("A matriz nao eh simetrica");
                return 0;
            }

            /*
                Sums each row of the matrix, and as it's symmetric, the rows are equal to the columns
                so, there is no need to sum each column
            */
            sums[i] += matrix[i][j];
        }

        // Using ternary operator, I separate the highest value and the lowest value
        biggestRow = biggestRow <= sums[i] ? sums[i] : biggestRow;
        smallestCol = smallestCol >= sums[i] ? sums[i] : smallestCol;
    }
    
    // Gets the difference
    difference = biggestRow - smallestCol;

    printf("A matriz eh simetrica , com diferenca %d", difference);
}