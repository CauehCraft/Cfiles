#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_linha 150

int main() {
    FILE *inteiros, *resultados;
    char * linha = (char*) malloc(tam_linha*sizeof(char));
    int nlinhas = 0, n = 10, i;
    int numeros[100];

    //verificando alocacao de linha
    if (linha == NULL) printf("Erro de alocação.");
    //lendo arquivos
    inteiros = fopen("entrada_q2.txt", "rt");
    resultados = fopen("resultados_q2.txt", "wt");
    //verificando se o arquivo foi lido com sucesso.
    if (inteiros == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
   //lendo cada linha do arquivo, salvando os dados, fazendo calculos e salvando no arquivo Resultados.
    
    
    
    for(i=0;i<n;i++){
        fscanf(inteiros, "%d\n", numeros);
        printf("%d\n", numeros[i]);
    }
    printf("\nNumero de linhas: %d\n", nlinhas);


    if(fclose(inteiros)!=0) printf("Erro ao fechar arquivo.");
    free(linha);
    return 0;
}
