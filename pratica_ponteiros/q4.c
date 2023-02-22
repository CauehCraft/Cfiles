#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3*pow(l, 2)*sqrt(3))/2;
    *perimetro = 6*l;
    printf("Area: %.2f\nPerimetro: %.2f", *area, *perimetro);
}

int main(void) {
    float a = 0, p = 0;
    float *area = &a, *perimetro = &p, l;
    printf("Digite o lado do hexagono para calcular a area e o perimetro: ");
    scanf("%f", &l);
    calcula_hexagono(l, area, perimetro);


    return 0;
}
