#include <stdlib.h>
#include <stdio.h>
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
	printf("\nComecou...\n");
	for(i=0;i<n;i++){
        //Turma *turma = turmas[i];
		printf("Turma %c\nVagas: %d\n", turmas[i]->id, turmas[i]->vagas);
	}
}

void matricula_aluno(Turma* turma, int mat, char* nome){

}


int main(){
    int op, mat, i, ii, turmas_criadas = 0, loop2=0;
    //Turma** turmas = (Turma**) malloc(MAX_TURMAS*sizeof(Turma));
    //Turma* turmas = malloc(MAX_TURMAS*sizeof(Turma*));
    /*
    for(i=0;i<MAX_TURMAS;i++){
        turmas[i] = malloc(MAX_TURMAS*sizeof(Turma));
    }
    
    for(i=0;i<MAX_TURMAS;i++){
        for(ii=0;ii<MAX_VAGAS;ii++){
            turmas[i]->alunos[ii] = NULL;
        }
    }
    if(turmas == NULL){
        printf("Erro de alocação!");
    }*/
    //Turma* turmas[MAX_TURMAS];
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
                    //turmas[turmas_criadas] = (Turma*) malloc(MAX_TURMAS*sizeof(Turma));
                    turmas[turmas_criadas] = criar_turma(id);
                    printf("Turma (%c) criada no slot(%d)", id, turmas_criadas);
                    turmas_criadas++;
                } else printf("Erro desconhecido!\n");
                /*
                for(i=0;i<MAX_TURMAS;i++){
                    printf("\nid da turma ->%c", turmas[i].id);
                    if(turmas[i].id == id){
                        //turmas[i] = *criar_turma(id);
                        printf("\nTurma (%c) ja existente no slot (%d).", id, i);
                        exist = 1;
                        break;
                    }
                    else printf("\n[IGNORAR] Turma (%c) nao esta neste slot!", id);
                }
                if(exist == 0){
                for(i=0;i<MAX_TURMAS;i++){
                    if(!turmas[i].id){
                        turmas[i] = *criar_turma(id);
                        printf("\nTurma %c criada com sucesso no slot (%d)\n", id, i);
                        break;
                    }
                    else printf("[IGNORAR] Erro aleatorio e ignoravel");
                }
                }*/
                break;
            case 2:
            	imprime_turmas(turmas, turmas_criadas);
                break;
            case 3:
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                for(i=0;i<turmas_criadas;i++){
                if(turmas[i]->id == id && turmas[i]->vagas>0){
                    printf("Matriculando aluno...\n");
                    printf("Digite a matricula: ");
                    scanf("%d", &mat);
                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", nome);
                    matricula_aluno(turmas[id], mat, nome);
                    printf("Aluno matriculado com sucesso!");
                    break;
                } else printf("Nao existe vaga nesta turma ou o id esta incorreto.");}
                
                
                printf("Caso 3");
                break;
            case 4:
                printf("Caso 4");
                break;
            case 5:
                printf("Caso 5");
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
