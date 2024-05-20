// Matheus, o mais matemático da Mat Aplicada.
#include <stdio.h>
#include <stdlib.h>

// Creating a struct with all the necessary attributes for the whole code to run
typedef struct _horto{
    int index;
    char name[10];
    float cost, price, growthRate, profit;
} horto;

// OOP, but in C, pt.1 - Getting a string based on the index
horto getPlantName(horto this){
    char plants[20][10] = {
        "rosa",
        "margarida",
        "girassol",
        "lirio",
        "dalia",
        "hibisco",
        "astromelia",
        "azaleia",
        "bonina",
        "hortensia",
        "mirtilo",
        "abacaxi",
        "acerola",
        "uva",
        "jabuticaba",
        "tomate",
        "oxicoco",
        "carambola",
        "cacau",
        "figo"
    };

    for(int i = 0; i < 10; i++){
        this.name[i] = plants[this.index - 1][i];
    }

    return this;
}

// OOP, but in C, pt.2 - Basic math time 😪
horto getProfit(horto this){
    this.profit = (this.price - this.cost) * (int)(28/this.growthRate) / 28;

    return this;
}

// Creates the array
horto *allocPlant(int n){
    horto *plants;
    plants = (horto*) malloc (sizeof(horto)*n);

    return plants;
}

// OOP, but in C, pt.4 - Prints the current 🌱
void printPlant(horto this){
    // Calls some functions to get the corrects name and profit
    this = getPlantName(getProfit(this));

    printf("%s: %.2f o/d\n", this.name, this.profit);

    return;
}

int main(){
    int n;

    // SCANs a Formatted Digit into the N var
    scanf("%d", &n);

    // Creates a pointer for the struct, then using dynamic memory I create an array 
    horto *plants;
    plants = allocPlant(n);

    // Loop for getting the users input
    for(int i = 0; i < n; i++){
        scanf("%d %f %f %f", &plants[i].index, &plants[i].cost, &plants[i].price, &plants[i].growthRate);
    }

    // Loop for printing the plants
    for(int i = 0; i < n; i++){
        printPlant(plants[i]);
    }

    // I clean the dynamic memory, than I set the plants as null
    free(plants);
    plants = NULL;

    return 0;
}