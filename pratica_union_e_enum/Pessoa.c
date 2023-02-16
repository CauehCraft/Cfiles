#include<stdio.h>
#include<stdlib.h>

typedef enum genero{
    MASCULINO,
    FEMININO
}Genero;

typedef struct pessoa{
    char nome[50];
    int idade;
    Genero generoU;
}Pessoa;

int main(){
    Pessoa pessoas;

    printf("Digite o nome da pessoa : ");
    scanf("%[^\n]s", pessoas.nome);
    printf("Digite a idade da pessoa : ");
    scanf("%d", &pessoas.idade);
    printf("Digite o genero da pessoa : ");
    scanf("%d", (int*)&pessoas.generoU);
    printf("%d", pessoas.generoU);
    printf("\nNome do pessoa: %s", pessoas.nome);
    printf("\nIdade: %d", pessoas.idade);
    if(pessoas.generoU == MASCULINO){
        printf("\nGenero: MASCULINO\n");
    }
    else printf("\nGenero: FEMININO\n");

    return 0;
}
