#include<stdio.h>
#include<stdlib.h>
//#include<locale.h>

typedef union tipo
{
    char ALIMENTO[50], BEBIDA[50], ELETRONICO[50];
}Tipo;


typedef struct produto{
    char nome[50];
    float preco;
    Tipo tipo;
}Produto;

void puxar_info(Produto * produto){
    int i;
    printf("\nNome do produto: %s", produto->nome);
    printf("\nPreco: R$ %.2f", produto->preco);
    printf("\nTipo: %s\n", produto->tipo.BEBIDA); 
}

void cadastrar_produto(Produto * produto){
    
    printf("Digite o nome do produto : ");
    scanf(" %[^\n]s", produto->nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &produto->preco);
    printf("Digite o tipo do produto: ");
    scanf(" %[^\n]s", produto->tipo.ALIMENTO); 
}


void main(){
    Produto * produtos = (Produto*) malloc(sizeof(Produto));
    if (produtos==NULL){
        printf("Erro de alocação de memoria");
        exit(1);
    };
    
    cadastrar_produto(produtos);
    puxar_info(produtos);
    free(produtos);

}
