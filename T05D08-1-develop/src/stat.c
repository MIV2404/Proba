#include <stdio.h>
#define NMAX 10

int input(int *data, int *n);
void output(int *data, int n);
int max(int *data, int n);
int min(int *data, int n);
double mean(int *data, int n);
double variance(int *data, int n);
void output_result(int max, int min, double mean, double variance);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    input(data, &n);
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
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
    return 0;
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
    double sigma = (max(data, n) - min(data, n)) + 1;
    sigma *= sigma;
    sigma--;
    return sigma / 12;
}

void output(int *data, int n) {
    if (n == 0) return;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", *(data + i));
        } else {
            printf("%d ", *(data + i));
        }
    }
    printf("\n");
}

void output_result(int max, int min, double mean, double variance) {
    if (mean != 0) {
        printf("%d %d %.6lf %.6lf", max, min, mean, variance);
    } else {
        printf("n/a");
    }
}