#include <stdlib.h>
#include <stdio.h>
#define MAX_VAGAS 40
#define MAX_TURMAS 5

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
    Turma* turma = (Turma*) malloc(sizeof(Turma));
    turma->id = id;
    for(i=0;i<MAX_VAGAS;i++){
        turma->alunos[i] = NULL;
    }
    return turma;
}

void imprime_turmas(Turma** turmas, int n){
	int i;
	printf("\nComecou...\n");
	for(i=0;i<n;i++){
		if(turmas[i]->id!=NULL){
			printf("Turma %c\n", turmas[i]->id);
		}
		else printf("Erro %d\n", i);
	}
}

int main(){
    int op, i;
    Turma* turmas = (Turma*) malloc(MAX_TURMAS*sizeof(Turma));
    for(i=0;i<MAX_VAGAS;i++){
        turmas->alunos[i] = NULL;
    }
    //Turma* turmas[MAX_TURMAS];
    char id;
    int loop = 0;
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\nAutor: CauehCraft\nVersao: 0.0.1\n");
    while(loop == 0){
        printf("\nMENU:\n1 – Criar turma\n2 – Listar turmas\n3 – Matricular aluno\n4 – Lancar notas\n5 – Listar alunos\n6 – Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Criando nova turma...\nDigite um id: ");
                scanf(" %c", &id);
                int exist = 0;
                for(i=0;i<MAX_TURMAS;i++){
                    printf("\nid da turma ->%c", turmas[i].id);
                    if(turmas[i].id == id){
                        //turmas[i] = *criar_turma(id);
                        printf("\nTurma %c ja existente.", id);
                        exist = 1;
                    }
                    else printf("\n[IGNORAR] Turma inexistente!\n");
                }
                if(exist == 0){
                for(i=0;i<MAX_TURMAS;i++){
                    if(turmas[i].id == NULL){
                        turmas[i] = *criar_turma(id);
                        printf("Turma %c criada com sucesso", id);
                        break;
                    }
                    else printf("[IGNORAR] Erro aleatorio e ignoravel");
                }
                }
                break;
            case 2:
            	printf("Comecando a 2...");
            	imprime_turmas(&turmas, MAX_TURMAS);
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
