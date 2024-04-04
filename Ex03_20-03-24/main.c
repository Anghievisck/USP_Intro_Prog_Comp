#include <stdio.h>

void main(){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    printf("Sequencia original: %d %d %d\n", a, b, c);

    if(a < b && a < c){
        if(b < c){
            printf("Sequencia ordenada: %d %d %d", a, b, c);
        } else {
            printf("Sequencia ordenada: %d %d %d", a, c, b);
        }
    } else if(b < a && b < c){
        if(a < c){
            printf("Sequencia ordenada: %d %d %d", b, a, c);
        } else {
            printf("Sequencia ordenada: %d %d %d", b, c, a);
        }
    } else if(c < a && c < b){
        if(a < b){
            printf("Sequencia ordenada: %d %d %d", c, a, b);
        } else {
            printf("Sequencia ordenada: %d %d %d", c, b, a);
        }
    }
}