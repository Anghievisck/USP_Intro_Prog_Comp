#include <stdio.h>
#include <stdbool.h>

// Creates a function that verifies if the student is valid or not depending on its grades and the total fails
bool verifyStudents(float fails, float avarage){
    if(fails < avarage){
        return true;
    } else if(fails < 10 && avarage > 8){
        return true;
    }
    return false;
}

int main(){
    // Creates some variables
    int numberStudents, numberDiscounts, totalStudents = 0, lastStudent;
    bool boolean;

    // Gets two intengers from the user
    scanf("%d %d", &numberDiscounts, &numberStudents);

    // Creates an array'
    float students[numberStudents][2];

    // As it reads the input from the user, it checks if it's valid for the discount ou no
    for(int i = 0; i < numberStudents; i++){
        scanf("%f %f", &students[i][0], &students[i][1]); 
        boolean = verifyStudents(students[i][0], students[i][1]);
        if(boolean){
            // If theres still discounts avaiable, it saves the last student, adds one to the total and
            // remove one discount from the total of discounts
            if(numberDiscounts > 0){
                totalStudents++;
                lastStudent = i + 1;
                numberDiscounts--;
            } else {
                // Verifies if its a valid student after the discounts are over 
                if(students[i][0] == students[i-1][0] && students[i][1] == students[i-1][1]){
                    totalStudents++;
                    lastStudent = i + 1;
                } else {
                    break;
                }
            }
        }
    }

    // Prints the correct output depending on the total of approved students
    if(totalStudents < 1){
        printf("0 alunos foram qualificados.");
    } else {
        printf("%d alunos foram qualificados. O ultimo qualificado foi o aluno numero %d", totalStudents, lastStudent);
    }

    return 0;
}