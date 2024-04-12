/*
    This is a C programm that count how many numbers is in the input
    also it shows the highest and lowest number
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    // Here I set the vars
    int totalNumbers = 0;
    float highest = 0, lowest = 10000, n;
    bool loop = true;

    // Here I create a loop responsible of reading all the numbers and saving the lowest and highest ones
    do{
        // Reads the user's input, than adds one to the total of inserted numbers
        scanf("%f", &n);
        totalNumbers++;

        /*
            Checks if the inserted number is lesses than the current lowest saved number,
            and it ignores any negative numbers
        */
        if(lowest > n && n >= 0){
            lowest = n; 
        }

        /*
            Checks if the inserted number is greater than the current highest saved number,
            and it ignores any number grater than 10k
        */
        if(highest < n && n <= 10000){
            highest = n;
        }

        /*
            To stop the loop, it checks if the inputted number is negative, then it prints the expected output,
            but it reduces by one the totalNumers, cuz' the negative number isn't supposed to be counted
        */
        if(n < 0){
            totalNumbers--;
            printf("%d\n%.2f\n%.2f", totalNumbers, highest, lowest);
            loop = false;
        }
    } while(loop);
}