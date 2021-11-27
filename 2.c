#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


void find_max_in_array(int *array, size_t n) {
    for (int i = 1; i < n; ++i) {
        if (array[0] < array[i]) {
            array[0] = array[i];
        }
    }
}

int main() {

    int m;
    int n;
    int **array;
    int row_number;
    generate_array_by_client(&array, &n, &m);


    printf("Array of maximum is \n\r");
    for (int i = 0; i < n; ++i) {
        find_max_in_array(array[i], m);
        int a = (array[i][0]);
        printf("%d \t", a);
    }
    printf("\r\n");

    return 1;
}