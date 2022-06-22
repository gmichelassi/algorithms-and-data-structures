// #########################################################
// #                         STACK                         #
// #                                                       #
// # - Inserção/exclusão sempre no topo da estrutura       #
// # - Utiliza como base uma lista ligada                  #
// # - Last In First Out                                   #
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
    element* top;
} stack;

// 1. Idêntico a Lista Ligada
void initialize(stack* s) {
    s->top = NULL;
}

// 2. Idêntico a Lista Ligada
void show(stack* s) {
    element* current = s->top;

    printf("\nPILHA");
    while(current != NULL) {
        printf("\n%d", current->content.key);
        current = current->next;
    }
}

// 3. Idêntico a Lista Ligada
element* search(stack* s, int key, element** previous) {
    *previous = NULL;
    element* current = s->top;

    while(current != NULL && current->content.key < key) {
        *previous = current;
        current = current->next;
    }

    if(current == NULL || current->content.key != key)
        return NULL;

    return current;
}


// 4. A inserção de itens em uma pilha ocorre sempre na primeira posição.
bool push(stack* s, item content) {
    element* new_element = (element*) malloc(sizeof(element));
    new_element->content = content;

    new_element->next = s->top;

    s->top = new_element;

    return true;
}

// 5. A remoção de um elemento em uma pilha também ocorre na primeira posição
bool pop(stack* s, item* content) {
    if(s->top == NULL) return false;

    *content = s->top->content;

    element* to_be_deleted = s->top;

    s->top = s->top->next;
    free(to_be_deleted);

    return true;
}


int main() {
    stack s;
    element* previous;

    initialize(&s);

    for(int i = 0; i < 10; i++) {
        item new_item;
        new_item.key = i;

        push(&s, new_item);
    }

    show(&s);

    item removed_item;

    pop(&s, &removed_item);

    printf("\nChave removida: %d", removed_item.key);

    item new_item;
    new_item.key = 27;
    push(&s, new_item);

    show(&s);

    return 1;
}