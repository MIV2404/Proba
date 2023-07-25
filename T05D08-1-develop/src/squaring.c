#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char ent;
    if (scanf("%d%c", n, &ent) != 2 || ent != '\n' || *n < 1) {
        return *n = 0;
    }

    int i = 0;

    for (int *p = a; i < *n; ++p) {
        if (i != *n - 1) {
            if (scanf("%d", p) != 1) {
                return *n = 0;
            }
        } else if (scanf("%d%c", p, &ent) != 2 || ent != '\n') {
            return *n = 0;
        }
        i++;
    }
    return 0;
}

void output(int *a, int n) {
    if (n == 0) {
        printf("n/a\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void squaring(int *a, int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}