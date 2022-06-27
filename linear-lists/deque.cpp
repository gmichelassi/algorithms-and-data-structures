// #########################################################
// #              Double Ended Queue (DEQUE)               #
// #                                                       #
// # - Inserção/exclusão nas extremidades da estrutura     #
// # - Utiliza como base uma lista ligada                  #
// # - Lista duplamente ligada                             #
// #########################################################

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int key;
} item;

typedef struct aux {
    item content;
    struct aux* next;
    struct aux* previous;
} element;

typedef struct {
    element* head;
} deque;


// 1. Para inicializar, basta ligar os ponteiros para formar a lista circular
void initialize(deque* d) {
    d->head = (element*) malloc(sizeof(element));
    d->head->next = d->head;
    d->head->previous = d->head;
}

// 2. Para mostrar, utilizamos o mesmo padrão da lista ligada circular
void show(deque* d) {
    element* current = d->head->next;

    printf("\nDEQUE");
    while(current != d->head) {
        printf("\n%d", current->content.key);
        current = current->next;
    }
}

// 3. Para buscar, percorremos a lista, elemento a elemento até encontrar o desejado.
// Muito parecido com a lista ligada circular, exceto pela parte que "retorna" o previous
element* search(deque* d, int key) {
    element* current = d->head->next;
    d->head->content.key = key;

    while (current->content.key < key) {
        current = current->next;
    }

    if(current != d->head && current->content.key == key) return current;

    return NULL;
}

// 4. Inserção (parte 1)
// Neste método faremos a inserção no fim da estrura.
bool insert_at_end(deque* d, item content) {
    element* new_element = (element*) malloc(sizeof(element));
    new_element->content = content;

    new_element->next = d->head;
    new_element->previous = d->head->previous;

    d->head->previous = new_element;
    new_element->previous->next = new_element;

    return true;
}

// 4. Inserção (parte 2)
// Neste médoto faremos a inserção no início da estrutura.
bool insert_at_beginning(deque* d, item content) {
    element* new_element = (element*) malloc(sizeof(element));
    new_element->content = content;

    new_element->next = d->head->next;
    new_element->previous = d->head;

    d->head->next = new_element;
    new_element->next->previous = new_element;

    return true;
}

// 5. Exclusão (parte 1)
// Neste método faremos a exclusão no começo da estrutura
bool remove_at_beginning(deque* d, item* content) {
    if(d->head->next == d->head) return false;

    element* to_be_deleted = d->head->next;
    *content = to_be_deleted->content;

    d->head->next = to_be_deleted->next;
    to_be_deleted->next->previous = d->head;

    free(to_be_deleted);

    return true;
}

// 5. Exclusão (parte 2)
// Neste método faremos a exclusão no fim da estrutura
bool remove_at_end(deque* d, item* content) {
    if(d->head->next == d->head) return false;

    element* to_be_deleted = d->head->previous;
    *content = to_be_deleted->content;

    d->head->previous = to_be_deleted->previous;
    to_be_deleted->previous->next = d->head;

    free(to_be_deleted);

    return true;
}

int main() {
    deque d;

    initialize(&d);

    for(int i = 0; i < 10; i++) {
        item new_item;
        new_item.key = i;

        insert_at_beginning(&d, new_item);
    }

    show(&d);

    item removed_item;

    remove_at_beginning(&d, &removed_item);
    printf("\nChave removida: %d", removed_item.key);

    remove_at_end(&d, &removed_item);
    printf("\nChave removida: %d", removed_item.key);

    show(&d);

    item new_item;
    new_item.key = 27;
    insert_at_end(&d, new_item);

    show(&d);

    return 1;
}