// #########################################################
// #                 HEAP SORT                             #
// #                                                       #
// # Este algoritmo utiliza uma estrutura heap máximo para #
// # ordenar um arranjo. Isso é feito devido a propriedade #
// # do heap na qual A[pai(i)] > A[i].                     #
// #                                                       #
// # Pior Caso      O(nlogn)                               #
// # Caso Médio     O(nlogn)                               #
// # Melhor Caso    O(nlogn)                               #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array);

void swap(int *array, int first_index, int second_index) {
	int tmp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = tmp;
}

int find_left_children(int node) {
    return 2 * node + 1;
}

int find_right_children(int node) {
    return 2 * node + 2;
}

void rebuild_max_heap(int *array, int current_node, int heap_size) {
    int left_children = find_left_children(current_node);
    int right_children = find_right_children(current_node);

    int greater;

    if (left_children < heap_size && array[left_children] > array[current_node]) {
        greater = left_children;
    } else {
        greater = current_node;
    }

    if (right_children < heap_size && array[right_children] > array[greater]){
        greater = right_children;
    }

    if (greater != current_node) {
        swap(array, current_node, greater);
        rebuild_max_heap(array, greater, heap_size);
    }
}

void build_max_heap(int *array, int heap_size) {
    for (int i = 0; i < heap_size; i++)
        rebuild_max_heap(array, i, heap_size);
}

void heap_sort(int *array, int lenght) {
    int heap_size = lenght;
    build_max_heap(array, heap_size);

    for (int i = heap_size - 1; i >= 0; i--) {
        swap(array, 0, i);
        heap_size--;
        rebuild_max_heap(array, 0, heap_size);
    }
}

int main() {
    int array[] = {
        13,  12,  63,  10,  61, 96,  30,  44,  70,  92,
        33,  88,  31,  88,  83, 76,  55,  82,  45,  87,
        42,  67,  37,  25,  63, 82,  75,  91,  67,  60,
        18,  70,  72,  81,  69, 77,  77,  99,  20,  46,
        91,  53,  34,  21,  40, 42,  96,  94,  23,  41
    };
    printf("Heap Sort\n");
    printf("Default: ");
    print_array(array);
    heap_sort(array, 50);
    printf("\nSorted: ");
    print_array(array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
