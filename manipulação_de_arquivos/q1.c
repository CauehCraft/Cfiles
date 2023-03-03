#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_linha 150

int main() {
    FILE *al_notas, *resultados;
    char * aluno = (char*) malloc(tam_linha*sizeof(char));
    int nlinhas = 0;
    char nome[100];
    float n1, n2, n3, media;

    //verificando alocacao de aluno
    if (aluno == NULL) printf("Erro de alocação.");
    //lendo arquivos
    al_notas = fopen("entrada_q3.txt", "rt");
    resultados = fopen("resultados.txt", "wt");
    //verificando se o arquivo foi lido com sucesso.
    if (al_notas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
   //lendo cada linha do arquivo, salvando os dados e fazendo  calculo da media e salvando no arquivo Resultados.
    while((fgets(aluno, tam_linha, al_notas))!=NULL){
        printf("%s", aluno); 
        sscanf(aluno, "%[^\t]\t%f\t%f\t%f", nome, &n1, &n2, &n3);
        media = (n1+n2+n3)/3;
        nlinhas++;
        fprintf(resultados, "%s\t%.2f\t%s\n", nome, media, (media>=7)?"Aprovado":"Reprovado");
    }
    printf("\nNumero de linhas: %d\n", nlinhas);


    if(fclose(al_notas)!=0) printf("Erro ao fechar arquivo.");
    free(aluno);
    return 0;
}
