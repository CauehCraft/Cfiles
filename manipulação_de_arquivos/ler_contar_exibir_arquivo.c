#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_linha 150

int main() {
    FILE * al_notas;
    char * aluno = (char*) malloc(tam_linha*sizeof(char));
    int nlinhas = 0;
    char *c;
    //verificando alocacao de aluno
    if (aluno == NULL) printf("Erro de alocação.");
    //lendo arquivo
    al_notas = fopen("entrada_q3.txt", "rt");
    //verificando se o arquivo foi lido com sucesso.
    if (al_notas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    //contando as linhas do arquivo
   
    while(c = fgets(aluno, tam_linha, al_notas)){
        printf("%s", aluno);
        if(*c == ' ') break;
        nlinhas++;
    }
    printf("\nNumero de linhas: %d\n", nlinhas);
     /*
    for(nlinhas=0;nlinhas<10;nlinhas++){
        
        printf("%c", *fgets(aluno, tam_linha, al_notas));
        printf("%s", aluno);
    }

    */
    //primeira linha
    
    

    //fputs("Hello World!", fp);
    if(fclose(al_notas)!=0) printf("Erro ao fechar arquivo.");
    free(aluno);
    return 0;
}
