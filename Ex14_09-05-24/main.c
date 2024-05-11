#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Creates a constant to use it instead of a random number
#define LENGTH 512 

int isHappy(int number){
    int counter, currentPower, displacement;

    currentPower = 1;
    counter = 0;

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

        // verifies if the number is one
        if(number == 1){
            return number;
        } 

        // verifies if the code entered a loop
        for(int j = 0; j < LENGTH; j++){
            if(i != j){
                if(sums[i] == sums[j]){
                    return number;
                }
            }
        }
    }
}

int main(){
    // Sets some vars
    int n;

    // Gets a value to n
    scanf("%d", &n);

    // Using a function I get the value of the sum
    n = isHappy(n);
    
    // if the sum is 1, n is a happy number, else it is a sad number
    if(n == 1){
        printf("Zangado estah alegre");
    } else {
        printf("Zangado estah sendo um mala");
    }

    return 0;
}