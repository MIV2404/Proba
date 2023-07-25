#include <math.h>
#include <stdio.h>

int division(int n, int i);
int simple_num_check(int n);

int main() {
    int n;
    char end;
    int result = 0;

    if (scanf("%d%c", &n, &end) != 1 && end != '\n') {
        printf("n/a\n");
        return 0;
    }

    n = fabs(n);

    for (int i = 1; i <= n; ++i) {
        if (division(n, i) == 1 && simple_num_check(i) == 1) {
            result = i;
        }
    }

    printf("%d\n", result);

    return 0;
}

int division(int n, int i) {
    while (n > 0) {
        n = n - i;
    }
    if (n == 0) {
        return 1;
    } else {
        return 0;
    }
}

int simple_num_check(int n) {
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (division(n, i) == 1) {
            count++;
        }
    }
    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}