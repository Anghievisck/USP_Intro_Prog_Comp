/*
        A C programm that builds a triangle of n-lines, with each element being the previous plus one
    and each line has one more element than the previous one.
    e.g.
    5
        1
        2   3
        4   5   6
        7   8   9  10
       11  12  13  14  15
*/

#include <stdio.h>

int main(){
    // Define two variables, one for the user's input, and one for the output 
    int n = 0, k = 1;

    // Requests the user for a integer
    scanf("%d", &n);

    // Checks if the inputted number is invalid (lesser than one)
    if(n < 1){
        printf("Este nao eh um numero natural valido");
    } else {
        // This for() is responsable for how many line will be printed
        for(int i = 0; i < n; i++){
            // This for() prints i-elements, being i the number of the current line
            for(int j = 0; j <= i; j++){
                printf("%3d ", k++);
            }

            // After all elements have been printed, it goes to the next line
            printf("\n");
        }
    }
}