#include <stdio.h>
#include <stdbool.h>

int main(){
    // Here I set the variables that I judged needed for the code to work
    int numberOfViewers, height, angryViewers = 0, heighestViewer = 0;
    bool condition = false;

    // Gets an integer from the user
    scanf("%d", &numberOfViewers);

    // This checks if the entered value is valid
    if(numberOfViewers < 1 || numberOfViewers > 1000){
    } else {
        condition = true;
    }

    // Creates one array
    int heightOfViewers[numberOfViewers];

    if(condition == true){

        // Here it gets various integers from the user to add to one array
        for(int i = 0; i < numberOfViewers; i++){
            scanf("%d", &height);

            if(height < 1 || height > 200){
                heightOfViewers[i] = 200;
            } else {
                heightOfViewers[i] = height;
            }
        }

        // Here it checks if the i-element is the biggest element yet to do certain things
        for(int i = 0; i < numberOfViewers; i++){
            if(heightOfViewers[i] >= heighestViewer){
                heighestViewer = heightOfViewers[i];
            } else {
                angryViewers++;
            }
        }
    }

    // Prints the total number of people that can't see the game
    printf("%d", angryViewers);
}