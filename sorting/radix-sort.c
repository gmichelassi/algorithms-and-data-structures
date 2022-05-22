// #########################################################
// #                 RADIX SORT                            #
// #                                                       #
// # Este algoritmo ordena os valores baseado nos digitos  #
// # do mais significativo para o menos significativo.     #
// #                                                       #
// # Complexidade   O(n) -> depende do algoritmo auxiliar  #
// # Estável?       Sim  -> depende do algoritmo auxiliar  #
// # in-place?      Não  -> depende do algoritmo auxiliar  #
// #########################################################

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array);

int get_maximum_value(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
        max = array[i];
    return max;
}

void counting_sort(int array[], int size, int place) {
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max)
        max = array[i];
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
        
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radix_sort(int array[], int lenght) {
    int max = get_maximum_value(array, lenght);

    for (int place = 1; max / place > 0; place *= 10)
        counting_sort(array, lenght, place);
}

int main() {
    int array[] = {
        13,  12,  63,  10,  61, 96,  30,  44,  70,  92,
        33,  88,  31,  88,  83, 76,  55,  82,  45,  87,
        42,  67,  37,  25,  63, 82,  75,  91,  67,  60,
        18,  70,  72,  81,  69, 77,  77,  99,  20,  46,
        91,  53,  34,  21,  40, 42,  96,  94,  23,  41
    };
    printf("Radix Sort\n");
    printf("Default: ");
    print_array(array);
    radix_sort(array, 50);
    printf("\nSorted: ");
    print_array(array);

    return 1;
}

void print_array(int *array) {
    for(int i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
}
