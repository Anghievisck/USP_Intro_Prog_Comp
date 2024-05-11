#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Creates a function that gets any 10 digits binary number and transforms it in a base 10 number
long long int vinaryToTen(long long int number){
    long long int holder;
    holder = 0;

    // Creates an array that saves the digits of the number
    for(int i = 0; i < 10; i++){
        holder += (number % pow(10, i+1)) / (pow(10, i)) * pow(2, i);
    }

    return holder;
}

int main(){
    int n, base;
    long long int cheaper, number;

    cheaper = 100000000000;

    // Gets an input from the user
    scanf("%d", &n);

    // Checks the base, than if it is a binary one, it goes to the function and then it checks if it is the
    // lowest number
    for(int i = 0; i < n; i++){
        scanf("%d", &base);
        scanf("%lld", &number);

        if(base == 10){
        } else if(base == 2){
            number = vinaryToTen(number);
        }

        if(cheaper >= number){
            cheaper = number;
        }
    }

    // Prints the lowest number
    printf("%lld", cheaper);
}