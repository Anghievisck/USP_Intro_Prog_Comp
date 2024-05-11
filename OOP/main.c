//  Trying some oop-ish things in C

#include <stdio.h>

typedef struct _singer{
    char name[248];
    int id, age;
    char status[16];
} singer;

singer NewSinger(char name[248], int age, int id, char status[16]){
    singer newSinger;

    newSinger.id = id;
    newSinger.age = age;

    for(int i = 0; i < 248; i++){
        newSinger.name[i] = name[i];
        if(i < 16){
            newSinger.status[i] = status[i];
        }
    }

    return newSinger;
}

int main(){
    FILE *f;
    int doing = 1, idHolder = 1, age;
    char name[248], status[16];

    f = fopen("listOfSingers.txt", "a");
    
    while(doing != 0){ 
        printf("\nInsert the name, age and the status of a singer:\n");
        scanf("%s", &name);
        scanf("%d", &age);
        scanf("%s", &status);

        if(name[0] == ' ' || status[0] == ' ' || age == 0){
            printf("puta que pariu, c é um cu");
        } else {
            singer currentSinger = NewSinger(name, age, idHolder, status);

            idHolder++;

            fprintf(f, "\nId:%d;Name:%s;Age:%d;Status:%s", currentSinger.id, currentSinger.name, currentSinger.age, currentSinger.status); 

            printf("\nDo you want to add another singer?\n1. Yes            0. No\n>>> ");
            scanf("%d", &doing);
        }

        // Reseting all vars
        age = 0;

        for(int i = 0; i < 248; i++){
            name[i] = ' ';
            if(i < 16){
                status[i] = ' ';
            }
        }
    }
}