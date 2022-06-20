// #########################################################
// #                      LINKED LIST                      #
// #                                                       #
// # - Cada elemento possui um sucessor e um antecessor    #
// # - Cada elemento possui uma referência para o sucessor #
// # - Ordem lógica não é a mesma da ordem física          #
// # - Alocação de memória sob demanda                     #
// # - Versão ordenada                                     #
// #########################################################

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int key;
} item;

typedef struct aux {
    item content;
    struct aux* next;
} element;

typedef struct {
    element* first;
} list;

// 1. Inicializar uma lista ligada é somente definir o primeiro elemento como null.
void initialize(list* l) {
    l->first = NULL;
}

// 2. Para imprimir os valores, basta percorrer a lista sequencialmente utilizando o ponteiro next.
void show(list* l) {
    element* current = l->first;

    printf("\nLISTA LIGADA");
    while(current != NULL) {
        printf("\n%d", current->content.key);
        current = current->next;
    }
}

// 3. Busca. Não é possível fazer busca binária.
// Nesse caso utilizamos um pequeno truque da linguagem C para retornar o elemento anterior também.
// **variable indidica um ponteiro para um ponteiro
element* search(list* l, int key, element** previous) {
    *previous = NULL;
    element* current = l->first;

    while(current != NULL && current->content.key < key) {
        *previous = current;
        current = current->next;
    }

    if(current == NULL || current->content.key != key)
        return NULL;

    return current;
}


// 4. Inserção (ordenada). É preciso encontrar a posição correta para se inserir e depois rearranjar os ponteiros.
bool insert(list* l, item content) {
    int key = content.key;
    element* previous;
    element* current = search(l, key, &previous);

    if(current != NULL) return false;
    current = (element*) malloc(sizeof(element));
    current->content = content;

    if(previous  == NULL) {
        current->next = l->first;
        l->first = current;
    } else {
        current->next = previous->next;
        previous->next = current;
    }

    return true;
}

// 5. De forma análoga, a exclusão libera o espaço de memória ocupado e reorganiza os ponteiros
bool remove(list* l, int key) {
    element* previous;
    element* current = search(l, key, &previous);

    if (current == NULL) return false;

    if (previous == NULL)
        l->first = current->next;
    else
        previous->next = current->next;

    free(current);

    return true;
}


int main() {
    list l;
    element* previous;

    initialize(&l);

    for(int i = 0; i < 10; i++) {
        item new_item;
        new_item.key = i;

        insert(&l, new_item);
    }

    show(&l);

    remove(&l, 7);
    remove(&l, 2);

    item new_item;

    new_item.key = 27;
    insert(&l, new_item);

    new_item.key = 13;
    insert(&l, new_item);

    show(&l);

    return 1;
}