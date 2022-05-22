// #########################################################
// #                 MERGE SORT                            #
// #                                                       #
// # Divisão e conquista, particionamos um array para      #
// # ordenar e juntar a solução por intercalação.          #
// #                                                       #
// # Pior Caso      O(nlogn)                               #
// # Caso Médio     O(nlogn)                               #
// # Melhor Caso    O(nlogn)                               #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array);

void merge(int array[], int beginning, int half, int ending) {
    int first_iterator, second_iterator, third_iterator;
    int first_array_lenght = half - beginning + 1;
    int second_array_lenght = ending - half;

    int first_array[first_array_lenght], second_array[second_array_lenght];

    for (first_iterator = 0; first_iterator < first_array_lenght; first_iterator++)
        first_array[first_iterator] = array[beginning + first_iterator];

    for (second_iterator = 0; second_iterator < second_array_lenght; second_iterator++)
        second_array[second_iterator] = array[half + 1 + second_iterator];

    first_iterator = 0;
    second_iterator = 0;
    third_iterator = beginning;

    while (first_iterator < first_array_lenght && second_iterator < second_array_lenght) {
        if (first_array[first_iterator] <= second_array[second_iterator]) {
            array[third_iterator] = first_array[first_iterator];
            first_iterator++;
        } else {
            array[third_iterator] = second_array[second_iterator];
            second_iterator++;
        }
        third_iterator++;
    }

    while (first_iterator < first_array_lenght) {
        array[third_iterator] = first_array[first_iterator];
        first_iterator++;
        third_iterator++;
    }

    while (second_iterator < second_array_lenght) {
        array[third_iterator] = second_array[second_iterator];
        second_iterator++;
        third_iterator++;
    }
}

void merge_sort(int *array, int beginning, int ending) {
    if(beginning < ending){
        int half = beginning + (ending - beginning) / 2;
        merge_sort(array, beginning, half);
        merge_sort(array, half + 1, ending);

        merge(array, beginning, half, ending);
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
    printf("Merge Sort\n");
    printf("Default: ");
    print_array(array);
    merge_sort(array, 0, 50);
    printf("\nSorted: ");
    print_array(array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
