#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_linha 150

int main() {
    FILE * al_notas;
    FILE * resultados;
    char * aluno = (char*) malloc(tam_linha*sizeof(char));
    int nlinhas = 0;
    char *c;
    char letter;
    //verificando alocacao de aluno
    if (aluno == NULL) printf("Erro de alocação.");
    //lendo arquivo
    al_notas = fopen("entrada_q3.txt", "rt");
    resultados = fopen("resultados.txt", "wt");
    //verificando se o arquivo foi lido com sucesso.
    if (al_notas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    //contando as linhas do arquivo
   
    while(c = fgets(aluno, tam_linha, al_notas)){
        printf("%s", aluno); 
        fputs(aluno, resultados);
        nlinhas++;
        if(*c == EOF) break;
    }
    printf("\nNumero de linhas: %d\n", nlinhas);


    if(fclose(al_notas)!=0) printf("Erro ao fechar arquivo.");
    free(aluno);
    return 0;
}
