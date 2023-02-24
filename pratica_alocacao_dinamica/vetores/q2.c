#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N_ALUNOS 10

int main(){
    int i, ii, n_aprovados = 0;
    char resp;
    float n_questoes, nota = 0;

    //Pedindo para o usuario definir a quantidade de questoes da prova
    printf("Digite a quantidade de questoes da prova: ");
    scanf("%f", &n_questoes);

    //alocação dinamica e verificacao de alocacao bem sucedida
    float *provas = (float*) malloc(N_ALUNOS*sizeof(float));
    char *gabarito = (char*) malloc(n_questoes*sizeof(char));
    if(provas == NULL || gabarito == NULL){
            printf("Erro de alocação de memoria\n");
            exit(1);
    }
    
    //Pedindo para o usuario digitar o gabrito
    printf("Digite o gabarito da prova com somente letras.\nEx.: 'a' ou 'B'\n");
    for(i=0;i<n_questoes;i++){
        printf("Questao %d: ", i+1);
        scanf(" %c", &gabarito[i]);
        gabarito[i] = toupper(gabarito[i]);
    }

    //Pedindo para o usuario digitar as respostas dos alunos
    for (i=0;i<N_ALUNOS;i++){
        printf("Digite as respostas do aluno %d\n", i+1);
        for (ii=0;ii<n_questoes;ii++){
            printf("Questao %d: ", ii+1);
            scanf(" %c", &resp);
            resp = toupper(resp);
            if(resp == gabarito[ii]){
                nota += 10/n_questoes;
            }
        }
        provas[i] = nota;
        nota = 0;
    }
    //Informando a nota dos alunos ao usuario
    for (i=0;i<N_ALUNOS;i++){
        printf("Aluno %d\nNota: %.2f\n", i+1, provas[i]);
        if (provas[i]>=6){
            n_aprovados++;
        }
    }

    //Calculando e exibindo percentual de aprovacao
    //aprovacao = n_aprovados*100/N_ALUNOS
    printf("Foram aprovados %d%% dos alunos!", n_aprovados*100/N_ALUNOS);

    //Liberando memoria
    free(provas);
    free(gabarito);
    return 0;
}