#include <math.h>
#include <stdio.h>

int input(int *data, int *n);
void output(int *data, int n);
int max(int *data, int n);
int min(int *data, int n);
double mean(int *data, int n);
double variance(int *data, int n);

int check(int *data, int n);

#define MAX 30

int main() {
    int n, data[MAX];

    if (input(data, &n) == 0) {
        printf("n/a");
    } else {
        printf("%d", check(data, n));
    }

    return 0;
}

int check(int *data, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] != 0 && data[i] % 2 == 0 && data[i] >= mean(data, n) &&
            data[i] <= mean(data, n) + 3 * sqrt(variance(data, n))) {
            result = data[i];
        }
    }
    return result;
}

int input(int *data, int *n) {
    char endl;

    if (scanf("%d%c", n, &endl) != 2 || endl != '\n' || *n < 1) {
        return *n = 0;
    }

    int i = 0;

    for (int *p = data; i < *n; ++p) {
        if (i == *n - 1) {
            if (scanf("%d%c", p, &endl) != 2 || endl != '\n') {
                return *n = 0;
            }
        } else if (scanf("%d", p) != 1) {
            return *n = 0;
        }
        i++;
    }
    return 1;
}

int max(int *data, int n) {
    if (n == 0) return 0;
    int temp = data[0];

    for (int i = 1; i < n; i++) {
        if (temp < data[i]) {
            temp = data[i];
        }
    }
    return temp;
}

int min(int *data, int n) {
    if (n == 0) return 0;
    int temp = data[0];

    for (int i = 1; i < n; i++) {
        if (temp > data[i]) {
            temp = data[i];
        }
    }

    return temp;
}

double mean(int *data, int n) {
    if (n == 0) return 0;
    double temp = data[0];

    for (int i = 1; i < n; i++) {
        temp += data[i];
    }

    return temp / n;
}

double variance(int *data, int n) {
    if (n == 0) return 0;
    double N = (max(data, n) - min(data, n)) + 1;
    N *= N;
    N--;
    return N / 12;
}