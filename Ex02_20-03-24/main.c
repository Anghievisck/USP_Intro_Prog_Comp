#include <stdio.h>

void main(){
    float priceTortilla, priceTejuine, priceManzapane, currentMoney;

    scanf("%f %f %f %f", &priceTortilla, &priceTejuine, &priceManzapane, &currentMoney);

    if(currentMoney < priceTortilla){
        printf("Dikson nao pode comprar nada");
    } else if(currentMoney >= (priceTortilla + priceTejuine + priceManzapane)){
        printf("Dikson pode comprar tortilla, tejuine e mazapane");
    } else if(currentMoney >= (priceTortilla + priceTejuine)){
        printf("Dikson pode comprar tortilla e tejuine");
    } else if(currentMoney >= priceTortilla){
        printf("Dikson pode comprar tortilla");
    }
}