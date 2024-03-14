#include <stdio.h>

void main(){
    int finalMinutes, totalHours, totalDays, finalPrice;
    
    // printf("Please insert the total of minutes of work:\n>>> ");
    scanf("%d", &finalMinutes);
    
    totalHours = finalMinutes/60;
    finalMinutes = finalMinutes%60;    
    totalDays = totalHours/12;
    totalHours = totalHours%12;

    finalPrice = (totalDays*1000)+(totalHours*130);

    printf("O orcamento eh de %d reais. O servico irah demorar %d diarias, %d horas e %d minutos.", finalPrice, totalDays, totalHours, finalMinutes);
}
