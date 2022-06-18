// #########################################################
// #                 LINEAR SEQUENTIAL LIST                #
// #                                                       #
// # - Cada elemento possui um sucessor e um antecessor    #
// # - Ordem lógica é a mesma da ordem física              #
// # - Versão ordenada                                     #
// # - Implementada utilizando um array                    #
// #########################################################
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

typedef struct {
    int key;
} item;

typedef struct {
    item content[MAX];
    int current_end;
} list;

// 1. Inicializar uma lista sequencial é somente definir o indície do último elemento.
// Como ela começa vazia, então o último índice é o 0.
void initialize(list* l) {
    l->current_end = 0;
}

// 2. Para imprimir os valores de uma lista sequencial, basta percorrer o vetor normalmente.
void show(list* l) {
    printf("\nLISTA SEQUENCIAL");
    for(int i = 0; i < l->current_end; i++) {
        printf("\n%d: %d", i, l->content[i].key);
    }
}

// 3. Inserção ordenada.
// Achamos a posição correta para inserir um determinado item. Deslocamos para direita todos os demais itens.
bool insert(list* l, item element) {
    int i = l->current_end;

    if(i >= MAX) return false;


    while(i > 0 && l->content[i-1].key > element.key) {
        l->content[i] = l->content[i-1];
        i--;
    }

    l->content[i] = element;
    l->current_end++;

    return true;
}

// 4. Busca Binária (logn)
// Como a lista é ordenada, é possível implementar busca binária.
int binary_search(list* l, int key) {
    int left, middle, right;
    left = 0;
    right = l->current_end;

    while(left <= right) {
        middle = (left + right) / 2;

        if(l->content[middle].key == key) return middle;
        if(l->content[middle].key < key) left = middle + 1;
        else right = middle - 1;
    }

    return -1;
}

// 5. Exclusão. 
// Remove um item escolhido e desloca para a esquerda os demais itens.
bool remove(list* l, int key) {
    int index = binary_search(l, key);

    if(index == -1) return false;

    for(int i = index; i < l->current_end - 1; i++) {
        l->content[i] = l->content[i+1];
    }

    l->current_end--;

    return true;
}

int main() {
    list l;

    initialize(&l);

    for(int i = 0; i < 10; i++) {
        item new_item;
        new_item.key = i;

        insert(&l, new_item);
    }

    show(&l);

    printf("\nÍndice do valor 4: %d", binary_search(&l, 4));

    remove(&l, 7);

    printf("\nÍndice do valor 7: %d", binary_search(&l, 7));

    show(&l);

    return 1;
}