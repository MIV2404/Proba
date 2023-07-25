#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n;  // размер массива
    double *data;

    if ((scanf("%d", &n) != 1 || n < 0)) {
        printf("NO");
    } else {
        data = (double *)malloc(n * sizeof(double));  // аллоцируем память:

        if (data != NULL) {
            input(data, n);

            if (make_decision(data, n))
                printf("YES");
            else
                printf("NO");
            free(data);
        } else {
            printf("NO");
        }
    }

    return 0;
}
