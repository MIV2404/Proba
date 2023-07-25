#include "data_stat.h"

double max(const double *data, int n) {
    if (n == 0) return 0;
    double temp = data[0];

    for (int i = 1; i < n; i++) {
        if (temp < data[i]) {
            temp = data[i];
        }
    }
    return temp;
}

double min(const double *data, int n) {
    if (n == 0) return 0;
    double temp = data[0];

    for (int i = 1; i < n; i++) {
        if (temp > data[i]) {
            temp = data[i];
        }
    }

    return temp;
}

double mean(const double *data, int n) {
    if (n == 0) return 0;
    double temp = data[0];

    for (int i = 1; i < n; i++) {
        temp += data[i];
    }

    return temp / n;
}

double variance(const double *data, int n) {
    if (n == 0) return 0;
    double sigma = (max(data, n) - min(data, n)) + 1;
    sigma *= sigma;
    sigma--;
    return sigma / 12;
}

void sort(double *data, int n) {
    int p;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                p = data[j];
                data[j] = data[j + 1];
                data[j + 1] = p;
            }
        }
    }
}