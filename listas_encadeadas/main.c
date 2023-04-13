#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void){
	Lista* list = lst_cria(); /*Cria uma lista*/
	list = lst_insere(list, 1); /*Insere o elemento na lista*/
	list = lst_insere(list, 2);
	list = lst_insere(list, 3);
	lst_imprime(list);
    list = lst_busca(list, 2);
    lst_imprime(list);
	return 0;
}
