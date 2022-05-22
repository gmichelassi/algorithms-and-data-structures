// #########################################################
// #                 QUICK SORT                            #
// #                                                       #
// # Divisão e conquista, particionamos um array dado um   #
// # pivô e ajeitamos o array de forma a manter os valores #
// # ordenados ao redor do pivô.                           #
// #                                                       #
// # Pior Caso      O(nˆ2) qnd pivô é o maior/menor valor  #
// # Caso Médio     O(nlogn)                               #
// # Melhor Caso    O(nlogn) qnd o pivô é a metade         #
// ######################################################### 

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array);

void swap(int *array, int first_index, int second_index) {
	int tmp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = tmp;
}

int partition(int *array, int beginning, int ending) {
    int pivot = array[ending];
    int first_iterator = beginning;
    int second_iterator = ending - 1;

    while(first_iterator <= second_iterator) {
        if (array[first_iterator] < pivot)
            first_iterator++;
        else if (array[second_iterator] > pivot)
            second_iterator--;
        else {
            swap(array, first_iterator, second_iterator);
            first_iterator++;
            second_iterator--;
        }
    }

    array[ending] = array[first_iterator];
    array[first_iterator] = pivot;

    return first_iterator;
}

void quick_sort(int *array, int beginning, int ending) {
    if (beginning < ending) {
        int pivot = partition(array, beginning, ending);
        quick_sort(array, beginning, pivot - 1);
        quick_sort(array, pivot + 1, ending);
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
    printf("Quick Sort\n");
    printf("Default: ");
    print_array(array);
    quick_sort(array, 0, 49);
    printf("\nSorted: ");
    print_array(array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}