#include <stdio.h>

int main(){
    // Create the variables
    int totalRows, totalCols, displacement, correctJ;

    // Gets 3 ints from the user
    scanf("%d %d %d", &totalRows, &totalCols, &displacement);

    // Verify if the inputed ints are valid
    if(totalRows > 0 && totalRows < 101 || totalCols > 0 && totalCols < 101 || displacement > 0 && displacement < totalCols){
        // Creates the matrix for the TV
        char displacedTV[totalRows][totalCols];

        // Fills the matrix
        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                scanf(" %c", &displacedTV[i][j]);
            }
        }

        // Prints the correctd version of the matrix
        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                if(j + displacement >= totalCols){
                    correctJ = j + displacement - totalCols;
                } else {
                    correctJ = j + displacement;
                }

                printf("%c", displacedTV[i][correctJ]);
            }

            printf("\n");
        }
    }
}