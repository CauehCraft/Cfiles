#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_VAGAS 4
#define MAX_TURMAS 4

typedef struct aluno { //criando a struct do tipo Aluno
    int mat;
    char nome[81];
    float notas[3], media;
}Aluno;

typedef struct turma { //criando a struct do tipo Turma
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* turmas[MAX_TURMAS]; //Variavel global para turma
int i, j; //Variaveis globais auxiliares

Turma* criar_turma(char id){ //Funcao para criar a turma, alocar o espaco de memoria e definir suas variaveis
    Turma * turma = (Turma*) malloc(sizeof(Turma)); //alocando dinamicamete a turma
    turma->id = id;
    turma->vagas = MAX_VAGAS;
    for(i=0;i<MAX_VAGAS;i++) turma->alunos[i] = NULL;
    return turma;
}

void imprime_turmas(Turma** turmas, int n){ //Funcao para imprimir na tela todas as turmas criadas e suas vagas disponiveis
    printf("\nListando turmas...\n");
    for(i=0;i<n;i++) printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
}

void matricula_aluno(Turma* turma, int mat, char* nome){ //Funcao para matricular um aluno a uma turma escolhida pela usuario, alocar memoria e definir suas respectivas variaveis
    for(j=0;j<MAX_VAGAS;j++){
        if(turma->alunos[j] == NULL) turma->alunos[j] = (Aluno*)malloc(sizeof(Aluno));
    }
    turma->alunos[MAX_VAGAS-turma->vagas]->mat = mat;
    strcpy(turma->alunos[MAX_VAGAS-turma->vagas]->nome, nome);  
    for(j=0;j<3;j++) turma->alunos[MAX_VAGAS-(turma->vagas)]->notas[j] = 0;
    turma->vagas--;
}

void lanca_notas(Turma* turma){ //Funcao para lancar notas de uma turma informada pelo usuario
    for(i=0;i<MAX_VAGAS-(turma->vagas);i++){    
        printf("Matricula: %d\tNome: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
        for(j=0;j<3;j++){
            printf("Digite a nota %d: ", j+1);
            scanf("%f", &turma->alunos[i]->notas[j]);
        }
        turma->alunos[i]->media = (turma->alunos[i]->notas[0]+turma->alunos[i]->notas[1]+turma->alunos[i]->notas[2])/3;
}}

void imprime_alunos(Turma* turma){ //Funcao para imprimir todos os alunos de uma turma fornecida pelo usuario
    for(i=0;i<MAX_VAGAS-(turma->vagas);i++) printf("Matricula: %d\nNome: %s\nMedia: %.1f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
}

Turma* procura_turma(Turma** turmas, int n, char id){ //Funcao auxiliar para fazer uma busca de turma pelo id fornecido pelo usuario
    for(i=0;i<n;i++) if(turmas[i]->id == id) return turmas[i]; else printf("\nTurma %c inexistente no slot %d!\n", id, i); return NULL;
}

int main(){ //Inicio da funcao principal do codigo
    int op, mat, turmas_criadas = 0, loop = 0; //Variaveis auxiliares da funcao main
    char id, nome[50];
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\nAutor: CauehCraft\nVersao: 0.0.1\n");
    while(loop == 0){//Criando um loop para o menu do programa
        printf("\nMENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        Turma* turm; //Criando uma turma auxiliar para utilizar fazer otimizacao no codigo
        switch(op){ //Criando switch com todos os cases para as opcoes que o usuario pode inserir
            case 1: // Primeiro case: Criar turma atraves da funcao respectiva
                printf("\nCriando nova turma...\nDigite um id: ");
                scanf(" %c", &id);
                if(turmas_criadas < MAX_TURMAS){ //Verificando se o limite de turmas foi atingido
                    turmas[turmas_criadas] = criar_turma(id);
                    printf("Turma (%c) criada no slot(%d)\n", id, turmas_criadas);
                    turmas_criadas++;
                } else printf("Erro! Maximo de turmas cadastradas atingido!\n");
                break;
            case 2: //Case 2 para imprimir na tela do usuario todas as turmas cadastradas com suas respectivas vagas
                imprime_turmas(turmas, turmas_criadas);
                break;
            case 3: //case 3 para matricular um aluno na turma fornecida pelo usuario e armazenar seu nome e sua matricula
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                turm = procura_turma(&turmas, turmas_criadas, id);
                if(turm!= NULL && turm->vagas > 0){
                        printf("Matriculando aluno...\nDigite a matricula: ");
                        scanf("%d", &mat);
                        printf("Digite o nome: ");
                        scanf(" %[^\n]s", nome);
                        matricula_aluno(turm, mat, &nome);
                        printf("Aluno matriculado com sucesso!\n");
                        break;
                } else printf("Nao existe vaga nesta turma ou o id esta incorreto.\n");
                break;
            case 4://Case 4 para lancar as notas de todos os alunos de uma turma fornecida pelo usuario
                printf("\nLancando notas...\nDigite o id da turma: ");
                scanf(" %c", &id);
                turm = procura_turma(&turmas, turmas_criadas, id);
                if(turm != NULL){
                    lanca_notas(turm);
                    break;
                } else printf("Erro ao lancar notas!\n");
                break;
            case 5://Case 5 para informar o nome, a matricula e a media de todos os alunos da turma fornecida pelo usuario
                printf("\nListando alunos...\nDigite o id da turma: ");
                scanf(" %c", &id);
                turm = procura_turma(&turmas, turmas_criadas, id);
                if(turm!= NULL){
                    imprime_alunos(turm);
                    break;
                }
                break;
            case 6: //Case 6 para finalizar o codigo
                printf("Obrigado por usar este programa!");
                loop = 1;
                break;
            default:
                break;
        }} //end loop
    for (i=0;i<MAX_TURMAS;i++) free(turmas[i]->alunos); //liberando o espaco alocado dos vetores
    for (i=0;i<MAX_TURMAS;i++) free(turmas[i]);
    return 0;
}