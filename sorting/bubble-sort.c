// #########################################################
// #                 BUBBLE SORT                           #
// #                                                       #                 
// # Percorrer o vetor N vezes trazendo o maior valor      #
// # atual para um índice cada vez maior.                  #
// #                                                       # 
// # Pior Caso      O(nˆ2)  vetor ordenado decrescente     #
// # Caso Médio     O(nˆ2)  vetor aleatório                #
// # Melhor Caso    O(n)    para o vetor já ordenado       #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void iteractive_bubble_sort(int *array, int lenght) {
    for(int i = lenght; i >= 0; i--) {
        for(int j = 1; j < i; j++) {
            if(array[j - 1] > array[j]) {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void recursive_bubble_sort(int *array, int lenght) {
    if (lenght < 0)
        return;

    for(int i = 1; i < lenght; i++) {
        if(array[i - 1] > array[i]) {
            int tmp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = tmp;
        }
    }

    recursive_bubble_sort(array, lenght - 1);
}

void print_array(int *array);

int main() {
    int first_array[] = {
        13,  12,  63,  10,  61, 96,  30,  44,  70,  92,
        33,  88,  31,  88,  83, 76,  55,  82,  45,  87,
        42,  67,  37,  25,  63, 82,  75,  91,  67,  60,
        18,  70,  72,  81,  69, 77,  77,  99,  20,  46,
        91,  53,  34,  21,  40, 42,  96,  94,  23,  41
    };
    printf("Iteractive Bubble Sort\n");
    printf("Default: ");
    print_array(first_array);
    iteractive_bubble_sort(first_array, 50);
    printf("\nSorted: ");
    print_array(first_array);

    int second_array[] = {
        54,  97,  38,  49,  15, 86,  32,  94,  13,  43,
        24,  18,  28,  70,  16, 81,  95,  50,  17,  26,
        90,  68,  62,  40,  19, 41,  33,  53,  74,  11,
        39,  14,  30,  78,  88, 27,  48,  20,  29,  58,
        83,  69,  87,  64,  61, 25,  66,  59,  82,  75
    };
    printf("\n\nRecursive Bubble Sort\n");
    printf("Default: ");
    print_array(second_array);
    recursive_bubble_sort(second_array, 50);
    printf("\nSorted: ");
    print_array(second_array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
