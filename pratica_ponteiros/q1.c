#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, y, *p;
    y = 0; // y definido como 0
    p = &y; //p recebe endereço de memoria de y
    x = *p; //x recebe o valor no endereco do ponteiro p, que é 0
    x = 4; // x definido como 4
    (*p)++; // valor no endereco do ponteiro p mais 1: 1
    --x; // x definido como 3
    (*p) += x; // valor no endereco do ponteiro p sera igual mais x: 1+3 = 4
    //ao final, x sera 3, p sera um ponteiro que aponta para o endereço de y que tem valor 4
    
    printf("%d %d %d", x, y, *p);
    

    return 0;
}
