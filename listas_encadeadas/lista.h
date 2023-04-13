typedef struct lista Lista;

// função que cria uma lista vazia (NULL)
Lista* lst_cria(void);

// função que insere um elemento no início da lista
Lista* lst_insere(Lista* l, int v);

//função que verifica se a lista está vazia
int lst_vazia(Lista *l);

//função que imprime os elementos da lista
void lst_imprime(Lista*l);

//função que busca um elemento na lista
Lista * lst_busca(Lista* l, int v);

//função que retira um elemento da lista
Lista * lst_retira(Lista*l, int v);

//função que libera a memória alocada para a lista
void lst_libera(Lista* l);

// função que insere de forma ordenada um elemento na lista
Lista* lst_insere_ordenada(Lista * l, int v);

// função que retorna o número de nós da lista que possuem o campo info com valores maiores do que n
int maiores(Lista* l, int n);

// função que retorna o ponteiro para o último nó de uma lista encadeada.
Lista* ultimo(Lista* l);

// função que recebe duas listas encadeadas e retorne a lista resultante da concatenação das duas listas
Lista* contatena(Lista* l1, Lista* l2);

// função que retire da lista todas as ocorrências de n e retorna a lista resultante
Lista* retira_n(Lista* l, int n);
