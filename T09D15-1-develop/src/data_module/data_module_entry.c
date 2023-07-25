#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n;  // размер массива
    double *data = NULL;

    if ((scanf("%d", &n) != 1 || n < 0)) {
        printf("ERROR");
    } else {
        data = (double *)malloc(n * sizeof(double));  // аллоцируем память:

        input(data, n);

        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }
        free(data);
    }

    return 0;
}