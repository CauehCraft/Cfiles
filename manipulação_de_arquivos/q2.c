#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_linha 150

int main() {
    FILE *inteiros, *resultados;
    char * linha = (char*) malloc(tam_linha*sizeof(char));
    int numeros[100], maior = 0, menor, i=0;
    float media = 0;

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
    while(fscanf(inteiros, "%d", &numeros[i])!=EOF){
        printf("%d\n", numeros[i]);
        if(numeros[i]>maior) maior = numeros[i];
        if(menor==NULL) menor=maior;
        if(numeros[i]<menor) menor=numeros[i];
        media += numeros[i];
        i++;
    }
    printf("\nNumero de linhas: %d\nMaior: %d\nMenor: %d\nMedia: %f\n", i, maior, menor, media/i);
    

    if(fclose(inteiros)!=0) printf("Erro ao fechar arquivo.");
    free(linha);
    return 0;
}
