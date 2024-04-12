#include <stdio.h>
#include <stdbool.h>

int main(){
    // Here I set the variables that I judged needed for the code to work
    int numberOfIngredients, item = 0, totalFood = 0; 
    bool condition = true;

    // Gets an integer from the user
    scanf("%d", &numberOfIngredients);

    // This checks if the entered value is valid
    if(numberOfIngredients < 1 || numberOfIngredients > 1000){
        condition = false;
    }

    // Creates two arrays
    int necessaryIngredients[numberOfIngredients], currentIngredients[numberOfIngredients];

    // Here it gets various integers from the user to add to one array
    for(int i = 0; i < numberOfIngredients; i++){
        scanf("%d", &item);

        // This checks if the entered value is valid
        if(item < 1 || item > 1000){
            condition = false;
        } else {
            necessaryIngredients[i] = item;
        }
    }

    // Same as the previous for-loop
    for(int j = 0; j < numberOfIngredients; j++){
        scanf("%d", &item);

        // This checks if the entered value is valid
        if(item < 1 || item > 100000){
            condition = false;
        } else {
            currentIngredients[j] = item;
        }
    }

    // Here I create a while-loop to check if how many times you will be able to fry a Jaca Coxinha
    while(condition != false){
        // This compares k-elements from both arrays to see if the conditions are met, if not, it stops the loop
        for(int k = 0; k < numberOfIngredients; k++){
            if(currentIngredients[k] >= necessaryIngredients[k]){
                condition = true;
            } else {
                condition = false;
                break;
            }
        }

        /*
            Here it adds to another variable one, and removes from the k-element from the 'current' array
            the k-element from the 'necessary' array.
        */
        if(condition == true){
            totalFood++;
            for(int l = 0; l < numberOfIngredients; l++){
                currentIngredients[l] = currentIngredients[l] - necessaryIngredients[l];
            }
        } else {
            condition = false;
        }
    }

    // In the ends, prints the number of total Coxinhas is possible to fry 
    printf("%d", totalFood);
}