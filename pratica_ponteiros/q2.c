#include <stdlib.h>
#include <stdio.h>
/*

int main(void) {
    int x, *p;
    x = 100;
    p = x;
    printf("Valor de p = %p\tValor de *p = %d", p, *p);

}

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:

a) Esta mensagem é de erro ou advertência?
Erro, pois a atribuição de p = x não pode ser executado.

b) Por que o compilador emite tal mensagem?
porque p é um ponteiro e x um inteiro.

c) Compile e execute o programa. A execução foi bem sucedida?
Não.

d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida
pelo compilador. */
int main(void) {
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d", p, *p);

}
/*
e) Compile e execute novamente o programa. A execução foi bem sucedida?
Sim, pois ao colocar o & na atribuição p = &x, eu estou atribuindo o endereço de x para o ponteiro p, que armazena endereço.
*/
