// #########################################################
// #                 SELECTION SORT                        #
// #                                                       #                 
// # Encontrar o maior/menor valor do vetor e posiciona-lo #
// # na última/primeira posição.                           #
// #                                                       # 
// # Pior Caso      O(nˆ2)  vetor ordenado decrescente     #
// # Caso Médio     O(nˆ2)  vetor aleatório                #
// # Melhor Caso    O(nˆ2)  para o vetor já ordenado       #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void iteractive_selection_sort(int *array, int lenght) {
    for(int i = lenght - 1; i >= 0; i--){
        int greater_value_index = i;

        for(int j = 0; j < i; j++){
            if(array[greater_value_index] < array[j]){
                greater_value_index = j;
            }
        }

        if(greater_value_index != i) {
            int tmp = array[i];
            array[i] = array[greater_value_index];
            array[greater_value_index] = tmp;
        }
    }
}

void recursive_selection_sort(int *array, int lenght) {
    if(lenght <= 0)
        return;
    
    int greater_value_index = 0;

    for(int i = 0; i < lenght; i++) {
        if(array[greater_value_index] < array[i]){
            greater_value_index = i;
        }
    }

    if(greater_value_index != lenght - 1) {
        int tmp = array[lenght - 1];
        array[lenght - 1] = array[greater_value_index];
        array[greater_value_index] = tmp;
    }

    recursive_selection_sort(array, lenght - 1);
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
    printf("Iteractive Selection Sort\n");
    printf("Default: ");
    print_array(first_array);
    iteractive_selection_sort(first_array, 50);
    printf("\nSorted: ");
    print_array(first_array);

    int second_array[] = {
        54,  97,  38,  49,  15, 86,  32,  94,  13,  43,
        24,  18,  28,  70,  16, 81,  95,  50,  17,  26,
        90,  68,  62,  40,  19, 41,  33,  53,  74,  11,
        39,  14,  30,  78,  88, 27,  48,  20,  29,  58,
        83,  69,  87,  64,  61, 25,  66,  59,  82,  75
    };
    printf("\n\nRecursive Selection Sort\n");
    printf("Default: ");
    print_array(second_array);
    recursive_selection_sort(second_array, 50);
    printf("\nSorted: ");
    print_array(second_array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
