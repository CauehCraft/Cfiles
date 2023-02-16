#include<stdio.h>
#include<stdlib.h>

typedef enum mes{
    janeiro = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Meses;

typedef struct data{
    int dia, ano;
    Meses mes;
}Data; 

int main(){
    Data data;
    printf("Digite o dia: ");
    scanf("%d", &data.dia);
    printf("Digite o mes: ");
    scanf(" %d", (int*)&data.mes);
    printf("Digite o ano: ");
    scanf("%d", &data.ano);
    printf("\nData digitada: %.2d/%.2d/%.4d\n", data.dia, data.mes, data.ano);
}
