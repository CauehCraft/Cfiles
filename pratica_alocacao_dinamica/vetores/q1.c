#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N_ENTREVISTADOS 4

int main(void){
    //Variaveis auxiliares
    int i, op, n_mulher=0, n_homem=0;
    float perc_f=0;
    float perc_m=0;

    //vetores dinamicos 
    char *sexo = (char*) malloc(N_ENTREVISTADOS*sizeof(char)); //Vetor onde fica armazenado o sexo dos entrevistados
    int *op_entrevistados = (int*) malloc(N_ENTREVISTADOS*sizeof(int)); //Vetor onde fica armazenado se o entervistado gostou ou nao
    //checando vetores
    if(sexo == NULL || op_entrevistados == NULL){
        printf("Erro de alocação de memoria\n");
        exit(1);
    } 
        
    for(i = 0; i<N_ENTREVISTADOS; i++){
        //Pedindo para o entrevistado digitar seu sexo
        printf("M = Masculino\nF = Feminino\n");
        printf("Digite seu sexo(M/F): \n");
        scanf(" %[^\n]", &sexo[i]);
        sexo[i] = toupper(sexo[i]);
        //Verificando se o entrevistado digitou uma opcao valida
        if(sexo[i]!='M' && sexo[i] != 'F'){
            printf("Digite somente M ou F!\n");
            i--;
        }
        else {
             //Perguntando se o entrevistado gostou ou nao do produto
            printf("Digite sua opiniao sobre o produto\n1- gostou.\n0- Nao gostou.\n");
            scanf("%i", &op);
            if(op!= 0 && op!=1){
                printf("Opcao invalida!\n");
                i--;
            }else op_entrevistados[i] = op;
        }
    } 
    for (i=0;i<N_ENTREVISTADOS;i++){
        //Adicionando contadores as variaveis
        if(sexo[i]=='M'){
            n_homem++;
        }
        else if(sexo[i]=='F'){
            n_mulher++;
        }
        if (op_entrevistados[i]==1 && sexo[i]=='F'){
            perc_f++;
        }
        else if (op_entrevistados[i]==0 && sexo[i]=='M'){
            perc_m++;
        }
    }
    
    //Calculando os percentuais e em seguida exibindo
    perc_f = n_mulher!=0 ? (perc_f*100)/n_mulher : 0;
    perc_m = n_homem!=0 ? (perc_m*100)/n_homem : 0;
    printf("Percentuais dos entrevistados:\n");
    printf("Mulheres que gostaram: %.1f%%\nHomens que nao gostaram: %.1f%%", perc_f, perc_m);
    
    //liberando memoria
    free(sexo);
    free(op_entrevistados);

    return 0;
}