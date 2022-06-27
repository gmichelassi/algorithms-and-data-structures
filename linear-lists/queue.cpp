// #########################################################
// #                         QUEUE                         #
// #                                                       #
// # - Inserção sempre no final da estrutura               #
// # - Exclusão sempre no início da estrutura              #
// # - Utiliza como base uma lista ligada                  #
// # - First In, First Out                                 #
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
    element* last;
} queue;

// 1. Idêntico a Lista Ligada
void initialize(queue* q) {
    q->first = NULL;
    q->last = NULL;
}

// 2. Idêntico a Lista Ligada
void show(queue* q) {
    element* current = q->first;

    printf("\nFILA");
    while(current != NULL) {
        printf("\n%d", current->content.key);
        current = current->next;
    }
}

// 3. Idêntico a Lista Ligada
element* search(queue* q, int key, element** previous) {
    *previous = NULL;
    element* current = q->first;

    while(current != NULL && current->content.key < key) {
        *previous = current;
        current = current->next;
    }

    if(current == NULL || current->content.key != key)
        return NULL;

    return current;
}

// 4. Inserção é feita no final da estrutura.
bool insert(queue* q, item content) {
    element* new_element = (element*) malloc(sizeof(element));
    new_element->content = content;

    new_element->next = NULL;

    if(q->first == NULL)
        q->first = new_element;
    else
        q->last->next = new_element;
    
    q->last = new_element;

    return true;
}


// 5. Exclusão é feita no início da estrutura.
bool remove(queue* q, item* content) {
    if(q->first == NULL) return false;

    element* to_be_deleted = q->first;
    *content = to_be_deleted->content;

    q->first = to_be_deleted->next;

    free(to_be_deleted);

    if(q->first == NULL)
        q->last = NULL;
    
    return true;
}


int main() {
    queue q;
    element* previous;

    initialize(&q);

    for(int i = 0; i < 10; i++) {
        item new_item;
        new_item.key = i;

        insert(&q, new_item);
    }

    show(&q);

    item removed_item;

    remove(&q, &removed_item);
    printf("\nChave removida: %d", removed_item.key);

    show(&q);

    return 1;
}