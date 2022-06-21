// #########################################################
// #                 CIRCULAR LINKED LIST                  #
// #                                                       #
// # - Cada elemento possui um sucessor e um antecessor    #
// # - Cada elemento possui uma referência para o sucessor #
// # - Ordem lógica não é a mesma da ordem física          #
// # - Alocação de memória sob demanda                     #
// # - O último elemento está ligado ao primeiro           #
// # - Existe um nó cabeça que está escondido do usuário   #
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
    element* head;
} list;


// 1. Inicializar essa estrutura consiste em criar o nó cabeça e fazer ele apontar para ele mesmo.
void initialize(list* l) {
    l->head = (element*) malloc(sizeof(element));
    l->head->next = l->head;
}

// 2. Para mostrar os elementos da lista ligada circular percorremos a lista desde o primeiro elemento até encontrar a cabeça novamente.
void show(list* l) {
    element* current = l->head->next;

    printf("\nLISTA LIGADA CIRCULAR");
    while(current != l->head) {
        printf("\n%d", current->content.key);
        current = current->next;
    }
}

// 3. Para buscar, percorremos a lista, elemento a elemento até encontrar o desejado.
// Utilizamos o mesmo truque já visto em listas ligadas para retornar o elemento anterior.
element* search(list* l, int key, element** previous) {
    *previous = l->head;
    element* current = l->head->next;

    l->head->content.key = key;

    while (current->content.key < key) {
        *previous = current;
        current = current->next;
    }

    if(current != l->head && current->content.key == key) return current;

    return NULL;
}

// 4. Inserção consiste em procurar pela posição ideal para o elemento a ser adicionado
// Então criamos o elemento e acertamos os ponteiros.
bool insert(list* l, item content) {
    element* previous;
    element* current = search(l, content.key, &previous);

    if(current != NULL) return false;

    current = (element*) malloc(sizeof(element));
    current->content = content;

    current->next = previous->next;
    previous->next = current;

    return true;
}

// 5. Exclusão, semelhante a inserção, fazemos uma busca para encontrar o elemento e seu anterior e depois ajeitamos os ponteiros.
bool remove(list* l, int key) {
    element* previous;
    element* current = search(l, key, &previous);

    if(current == NULL) return false;

    previous->next = current->next;
    
    free(current);
    
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