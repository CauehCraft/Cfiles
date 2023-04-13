#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void main(void){
	Lista* list = lst_cria(); /*Cria uma lista*/
    Lista* list2 = lst_cria();
	list = lst_insere_ordenada(list, 1); /*Insere o elemento na lista*/
	list = lst_insere_ordenada(list, 3);
	list = lst_insere_ordenada(list, 2);
    list = lst_insere_ordenada(list, 5);
    list2 = lst_insere_ordenada(list2, 0);
    list2 = lst_insere_ordenada(list2, 6);
    list2 = lst_insere_ordenada(list2, 7);
    list2 = lst_insere_ordenada(list2, 7);
    list2 = lst_insere_ordenada(list2, 7);
    list2 = lst_insere_ordenada(list2, 7);
    list2 = lst_insere_ordenada(list2, 4);
    lst_imprime(list);
    printf("-\n");
    lst_imprime(list2);
    
    int m = maiores(list, 3);
    printf("Total de números maiores que 3 na lista 1: %d \n", m);
    m = maiores(list2, 3);
    printf("Total de números maiores que 3 na lista 2: %d \n", m);
    Lista* ult = ultimo(list);
    printf("Valor do ultimo no na lista1: %d \n", ult->info);
    ult = ultimo(list2);
    printf("Valor do ultimo no na lista2: %d \n", ult->info);

    Lista* listas_concatenadas = contatena(list, list2);

    retira_n(listas_concatenadas, 7);
    lst_imprime(listas_concatenadas);
}
