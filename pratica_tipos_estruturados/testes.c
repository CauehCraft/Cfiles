#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_VAGAS 4
#define MAX_TURMAS 4

typedef struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* turmas[MAX_TURMAS];

Turma* criar_turma(char id){
    int i;
    Turma * turma = (Turma*) malloc(sizeof(Turma));
    turma->id = id;
    turma->vagas = MAX_VAGAS;
    for(i=0;i<MAX_VAGAS;i++){
        turma->alunos[i] = NULL;
    }
    return turma;
}

void imprime_turmas(Turma** turmas, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
	}
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int j;
    for(j=0;j<MAX_VAGAS;j++){
        if(turma->alunos[j] == NULL){
        turma->alunos[j] = (Aluno*)malloc(sizeof(Aluno));
    }
    }
    
    turma->alunos[MAX_VAGAS-turma->vagas]->mat = mat;
    strcpy(turma->alunos[MAX_VAGAS-turma->vagas]->nome, nome);
    //turma->alunos[MAX_VAGAS-turma->vagas]->nome = nome;
    
    for(j=0;j<3;j++){
        turma->alunos[MAX_VAGAS-(turma->vagas)]->notas[j] = 0;
    } 
    turma->vagas--;
}

void lanca_notas(Turma* turma){
    int i, j;
	for(i=0;i<MAX_VAGAS-(turma->vagas);i++){    
        printf("Matricula: %d\tNome: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
        for(j=0;j<3;j++){
            printf("Digite a nota %d: ", j+1);
            scanf("%f", &turma->alunos[i]->notas[j]);
        }
        turma->alunos[i]->media = (turma->alunos[i]->notas[0]+turma->alunos[i]->notas[1]+turma->alunos[i]->notas[2]);
	}
}
void imprime_alunos(Turma* turma){
    int i, j;
	for(i=0;i<MAX_VAGAS-(turma->vagas);i++){    
        printf("Matricula: %d\nNome: %s\nMedia: %.1f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
	}
}


int main(){
    int op, mat, i, ii, turmas_criadas = 0, loop2=0;
    char id, nome[50];
    int loop = 0;
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\nAutor: CauehCraft\nVersao: 0.0.1\n");
    while(loop == 0){
        printf("\nMENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        int exist = 0;
        switch(op){
            case 1:
                printf("Criando nova turma...\nDigite um id: ");
                scanf(" %c", &id);
                if(turmas_criadas < MAX_TURMAS){
                    turmas[turmas_criadas] = criar_turma(id);
                    printf("Turma (%c) criada no slot(%d)", id, turmas_criadas);
                    turmas_criadas++;
                } else printf("Erro desconhecido!\n");

                break;
            case 2:
            	imprime_turmas(turmas, turmas_criadas);
                break;
            case 3:
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                for(i=0;i<turmas_criadas;i++){
                    if(turmas[i]->id == id && turmas[i]->vagas>0){
                        printf("Matriculando aluno...\nDigite a matricula: ");
                        scanf("%d", &mat);
                        printf("Digite o nome: ");
                        scanf(" %[^\n]s", nome);
                        matricula_aluno(turmas[i], mat, &nome);
                        printf("Aluno matriculado com sucesso!");
                        break;
                } else printf("Nao existe vaga nesta turma ou o id esta incorreto.");}

                break;
            case 4:
                printf("Lancando notas...\nDigite o id da turma: ");
                scanf(" %c", &id);
                for(i=0;i<turmas_criadas;i++){
                    if(turmas[i]->id == id){
                        lanca_notas(turmas[i]);
                        break;
                    }
                }
                break;
            case 5:
                printf("Listando alunos...\nDigite o id da turma: ");
                scanf(" %c", &id);
                for(i=0;i<turmas_criadas;i++){
                    if(turmas[i]->id == id){
                        imprime_alunos(turmas[i]);
                        break;
                    }
                }
                break;
            case 6:
                break;
            default:
                break;
        }

        } //end loop
    
    free(turmas);
    return 0;
}
