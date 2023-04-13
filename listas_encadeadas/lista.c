#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    int info;
    struct lista* prox;
};

Lista* lst_cria(void){
    return NULL;
}

/* inserção no inicio: retorna a lista atualizada */
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime(Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox)
        printf(" Info = %d \n", p->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* função busca: busca um elemento na lista */
Lista* lst_busca(Lista* l, int v){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;
}

/* função retira: */
Lista * lst_retira(Lista*l, int v){
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p->info!=v){
    	if (p==NULL)
        	return l; /* n�o achou: retorna lista original */
        ant = p;
        p = p->prox;
            /* verifica se achou elemento */
    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        l = p->prox;
    else
    /* retira elemento do meio da lista */
        ant->prox = p->prox;
    free(p);
    return l;
}

/* função libera: libera elementos alocados */
void lst_libera(Lista* l){
    Lista* p = l;
    Lista* t;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}

Lista* lst_insere_ordenada(Lista * l, int v){
	Lista * novo;
	Lista * ant = NULL;
	Lista * p =l;
	while(p!=NULL && p->info<v){
		ant = p;
		p = p->prox;

	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	if(ant ==NULL){
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return l;
}
