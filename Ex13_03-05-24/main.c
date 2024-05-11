#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Creates a constant to use it instead of a random number
#define LENGTH 512 

int main(){
    // Sets some vars
    int number, counter, currentPower, displacement;

    // Defines the value of two vars, so I can use the '++' and '*=' operators 
    currentPower = 1;
    counter = 0;

    // Gets a integer from the user
    scanf("%d", &number);

    // Creates an array to keep the sums of digit from the inputted number, and then sets all it's values to 0
    int sums[LENGTH];
    for(int i = 0; i < LENGTH; i ++){
        sums[i] = 0;
    }

    // All the logic needs to be done in a for-loop
    for(int i = 0; i < LENGTH; i ++){
        currentPower = 1;
        counter = 0;

        // Gets the total number of digits from the inputted number using powers of ten
        while(true){
            if(number >= currentPower){
                counter++;
                currentPower *= 10;
            } else {
                currentPower = 1;
                displacement = counter - 1;

                break;
            }
        }

        // Creates a array to save the digits from said number
        int vetorOfNumber[counter];

        // Fills the array with the correct unit, dozen, hundred etc...
        for(int j = 0; j < counter; j++){
            currentPower *= 10;
            vetorOfNumber[displacement - j] = (number % currentPower) / (currentPower / 10);
        }

        // Saves the sum of squares of each digit 
        for(int j = 0; j < counter; j++){
            sums[i] += pow(vetorOfNumber[j], 2);  
        }

        // Sets the var number as the current sum, to create a pseudo-dynamic array
        number = sums[i];

        // Verifies if the number is in fact, a 'happy' one
        if(number == 1){
            printf("Zangado estah alegre");
            return 0;
        } 

        // If the number isn't 'happy', it checks if the sums entered a loop
        for(int j = 0; j < LENGTH; j++){
            if(i != j){
                if(sums[i] == sums[j]){
                    printf("Zangado estah sendo um mala");
                    return 0;
                }
            }
        }
    }

    return 0;
}