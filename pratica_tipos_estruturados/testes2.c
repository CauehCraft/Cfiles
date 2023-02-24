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
        Turma *turma = turmas[i];
		printf("Turma %c\nVagas: ", turma[i].id, turma[i].vagas);
	}
}

int main(){
    int op, i, turmas_criadas = 0;
    //Turma** turmas = (Turma**) malloc(MAX_TURMAS*sizeof(Turma));
    Turma** turmas = malloc(MAX_TURMAS*sizeof(Turma*));
    /*
    for(i=0;i<MAX_TURMAS;i++){
        turmas[i] = malloc(MAX_TURMAS*sizeof(Turma));
    }
    
    for(i=0;i<MAX_VAGAS;i++){
        turmas->alunos[i] = NULL;
    }
    */
    
    if(turmas == NULL){
        printf("Erro de alocação!");
    }
    //Turma* turmas[MAX_TURMAS];
    char id;
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
                    turmas[turmas_criadas] = (Turma*) malloc(MAX_TURMAS*sizeof(Turma));
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
            	printf("Comecando a 2...");
            	imprime_turmas(&turmas, turmas_criadas);
                printf("Caso 2");
                break;
            case 3:
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
