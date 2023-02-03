#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tam = 10;
    int i;
    int * vetor = (int* ) malloc(tam * sizeof(int));
    
    if(vetor == NULL){
        printf("Erro\n");
        exit(1);
    }
    for( i = 0; i<10 ;i++){
        vetor[i] = i;
    }
    for ( i = 0; i < 10; i++){
        printf("%i\n", vetor[i]);
    }
    
    free(vetor);
    return(0);

}
