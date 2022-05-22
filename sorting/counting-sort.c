// #########################################################
// #                 COUNTING SORT                         #
// #                                                       #                 
// # Ordenação baseada na contagem de elementos de valores #
// # diferentes.                                           #
// #                                                       # 
// # Complexidade   O(n)                                   #
// # Estável?       Sim                                    #
// # in-place?      Não                                    #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array);

void counting_sort(int array[], int lenght) {
    int output[99];

    int max = array[0];
    for (int i = 1; i < lenght; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int count[99];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < lenght; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = lenght - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < lenght; i++) {
        array[i] = output[i];
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
    printf("Counting Sort\n");
    printf("Default: ");
    print_array(array);
    counting_sort(array, 50);
    printf("\nSorted: ");
    print_array(array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
