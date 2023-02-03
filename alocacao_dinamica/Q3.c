#include <stdio.h>
#include <stdlib.h>

int main(void){
    int qtd_frutas, linha;
    
    printf("Digite a quantidade de frutas: \n");
    scanf("%d", &qtd_frutas); 
    
    char ** frutas = (char**) malloc(qtd_frutas*sizeof(char*));
    
    if(frutas==NULL){ 
        printf("Erro");
        exit(1);
    } 
    
    for(linha=0;linha<qtd_frutas; linha++){
        frutas[linha] = (char*) malloc(50*sizeof(char));
    }   
    
    float * preco_frutas = (float*) malloc(qtd_frutas*sizeof(float));

    if(preco_frutas==NULL){
        printf("Error");
        exit(1);
    }
    
    for(linha=0; linha<qtd_frutas; linha++){
        printf("Digite o nome da fruta: ");
        scanf(" %[^\n]s", frutas[linha]);
        printf("digite o preço da fruta: ");
        scanf("%f", &preco_frutas[linha]);
    } 
    
    printf("Lista de frutas \n");
    printf("---------------------\n"); 
    for(linha=0; linha<qtd_frutas; linha++){
        printf("%s - R$%.2f \n", frutas[linha], preco_frutas[linha]);
    }

    for(linha=0; linha< qtd_frutas ; linha++){
        free(frutas[linha]);
    }
    free(frutas);
    free(preco_frutas);

    return 0;
}
