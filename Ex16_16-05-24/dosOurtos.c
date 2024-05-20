#include <stdio.h>
#include <stdlib.h>

typedef struct _planta{
    int indice;
    float custo, venda, tempo;
} planta;

planta *allocaPlanta(int n){
    planta *plantas;
    plantas = (plantas*) malloc (sizeof(planta)*n);

    return plantas;
}

int main(){
    int n;
    float lucro;
    char plantas[20][10] = {
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

    scanf("%d", &n);

    planta *plantas;
    plantas = alocaPlanta(n);

    for(int i = 0; i < n; i++){
        scanf("%d %f %f %f", &plantas[i].indice, &plantas[i].custo, &plantas[i].venda, &plantas[i].tempo);
    }

    for(int i = 0; i < n; i++){
        lucro = (plantas[i].venda - plantas[i].custo) * (int)(28/plantas[i].tempo) / 28
        printf("%s: %.2f o/d\n", plantas[plantas[i].indice - 1], lucro);
    }

    free(plantas);
    plantas = NULL;

    return 0;
}