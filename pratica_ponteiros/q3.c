
#include <stdio.h>
int main(void) {
    int a, b, c, d;
    int *p1;
    int *p2 = &a; //p2 recebe endereço de a
    int *p3 = &c; //p3 recebe endereço de c
    p1 = p2; //p1 recebe p2: p1->p2->a
    *p2 = 10; //valor de p2 definido como 10: p1->p2->a = 10
    b = 20; //valor de b definido como 20: b = 20
    int **pp;
    pp = &p1; //pp recebe endereço de p1 que é um ponteiro para o endereço de a: pp->p1->a = 10
    *p3 = **pp; //p3 recebe o valor do ponteiro para ponteiro pp, que aponta para a: p3->c = pp->p1->a = 10
    int *p4 = &d; //valor de p4 definido como endereço de d: p4->d
    *p4 = b + (*p1)++; //valor de p4 que é o valor de d será definido como b + valor de p1 acrescido de 1: p4->d = b + (p1->a)++  => a=11; d = 20+10 = 30
    //ao final temos a = 11; b = 20; c = 10; d = 30
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);

    return 0;
}
