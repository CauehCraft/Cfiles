#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tam = 3, j, i;
    int ** matriz = (int**) malloc(tam*sizeof(int*));
    
    for (i=0;i<tam;i++){
        matriz[i] = (int*) malloc(tam*sizeof(int));
    }
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            matriz[i][j] = i*3 + j;
        }
    }
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("%d ",matriz[i][j]);  
        }
        printf("\n");
   }
    for(i=0;i<tam;i++){
        free(matriz[i]);
    }
    free(matriz);
}
