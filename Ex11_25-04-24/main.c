#include <stdio.h>

// Creating a struct for the code
typedef struct _cheerleader{
    double height, strength, age;
    char position; 
} cheerleader;

// Creating a pseudo-constructor for the cheerleader struct
cheerleader NewCheerleaders(double height, double strength, double age, char position){
    cheerleader newCheerleaders;

    if(height >= 1 && height <= 200){
        newCheerleaders.height = height;
    }

    if(strength >= 1 && strength <= 100){
        newCheerleaders.strength = strength;
    }

    if(age >= 1 && age <= 100){
        newCheerleaders.age = age;
    }

    if(position == 'F' || position == 'B'){
        newCheerleaders.position = position;
    }

    return newCheerleaders;
}

int main(){
    // Creating all necessary variables
    int numberOfCheerleaders;
    double ijScore = 0, jiScore = 0, greatestScore = 0;
    double height, strength, age;
    char position;

    // Gets the total number of people
    scanf("%d", &numberOfCheerleaders);

    // Checks if set number of people is valid
    if(numberOfCheerleaders > 0 && numberOfCheerleaders < 1001){
        // Creates two arrays, one for the bases and one for the fliers
        cheerleader bases[numberOfCheerleaders];
        cheerleader fliers[numberOfCheerleaders];

        for(int i = 0; i < numberOfCheerleaders; i++){
            // Initialize the arrarys with a default caracteristic, that assures the following logic
            bases[i].age = 0;
            fliers[i].age = 0;
        }

        for(int i = 0; i < numberOfCheerleaders; i++){
            // Gets all the inputs for the user
            scanf("%lf %lf %lf %c", &height, &strength, &age, &position);

            // Fill the correct array based on each person position
            if(position == 'B'){
                bases[i] = NewCheerleaders(height, strength, age, position);
            } else if(position == 'F'){
                fliers[i] = NewCheerleaders(height, strength, age, position);
            }
        }

        for(int i = 0; i < numberOfCheerleaders; i++){
            for(int j = 0; j < numberOfCheerleaders; j++){
                // Verifies if the i-element and j-element from each array exists
                if(bases[i].age == 0 || fliers[j].age == 0){
                } else {
                    // Sets the score for the i-base and j-flyer
                    ijScore =  fliers[j].height * bases[i].age * (bases[i].strength + fliers[j].strength);
                }
                if(bases[j].age == 0 || fliers[i].age == 0){
                } else {
                    // Sets the score for the j-base and i-flyer
                    jiScore =  fliers[i].height * bases[j].age * (bases[j].strength + fliers[i].strength);
                }
                
                // Compares each score to save the greatest
                if(greatestScore > ijScore && greatestScore > jiScore){
                    greatestScore = greatestScore;
                } else {
                    if(ijScore >= jiScore){
                        greatestScore = ijScore;
                    } else {
                        greatestScore = jiScore;
                    }
                }
            }
        }
        // Prints the highest score possible between all the different pairs
        printf("%.2lf", greatestScore);
    }
}