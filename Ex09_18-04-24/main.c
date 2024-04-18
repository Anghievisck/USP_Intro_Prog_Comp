// This is a phone number verifier written in C

#include <stdio.h>
#include <stdbool.h>

int main(){
    // I created the variable as a char array to let me read each character with ease
    char phoneNumber[11];
    bool status;
    
    // This gets the phone number from the user's input
    for(int i = 0; i < 11; i++){
        scanf("%c", &phoneNumber[i]);
    }

    // This is a long if-else chain, using switch-case, that verifies if each characters is valid  
    if(phoneNumber[0] != '1'){
        status = false;
    } else {
        if(phoneNumber[1] != '0'){
            if(phoneNumber[2] == '9'){
                switch (phoneNumber[3]){
                case '5':
                    status = true;
                    break;
                
                case '6':
                    status = true;
                    break;
                
                case '7':
                    status = true;
                    break;
                
                case '8':
                    status = true;
                    break;
                
                case '9':
                    status = true;
                    break;
                
                default:
                    status = false;
                    break;
                }

                if(status){
                    for(int i = 4; i < 11; i++){
                        if(phoneNumber[i] != '0'){
                            status = true;
                            break;
                        } else {
                            status = false;
                        }
                    }
                }
            }
        }
    }

    if(status){
        printf("O numero existe");
    } else {
        printf("O numero nao existe");
    }
}