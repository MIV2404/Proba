#include <stdio.h>

#define MAX 10

void input(int *buffer, int *length, int *shift);
void shifting(int *buffer, int length, int shift);
void swap(int *a, int *b);
void output(int *data, int length);

int main() {
    int buffer[MAX], length, shift;

    input(buffer, &length, &shift);

    if (length == 0 || shift == 0) {
        printf("n/a");
    }

    shifting(buffer, length, shift);

    if (shift != 0) {
        output(buffer, length);
    }

    return 0;
}

void input(int *buffer, int *length, int *shift) {
    char endl;

    if (scanf("%d%c", length, &endl) != 2 || endl != '\n') {
        *length = 0;
        *shift = 0;
    } else if (*length <= 0 || *length > 10) {
        *length = 0;
        *shift = 0;
    }
    if (*length != 0) {
        int i = 0;
        for (int *p = buffer; i < *length; ++p) {
            if (i == *length - 1) {
                if (scanf("%d%c", p, &endl) != 2 || endl != '\n') {
                    *length = 0;
                    *shift = 0;
                }
            } else if (scanf("%d", p) != 1) {
                *length = 0;
                *shift = 0;
            }
            i++;
        }
        if (scanf("%d%c", shift, &endl) != 2 || endl != '\n') {
            *length = 0;
            *shift = 0;
        }
    }
}

void shifting(int *buffer, int length, int shift) {
    if (shift > 0) {
        for (int i = 0; i < shift; i++) {
            for (int j = 1; j < length; j++) {
                swap(&buffer[j], &buffer[j - 1]);
            }
        }
    } else {
        for (int i = 0; i < -shift; i++) {
            for (int j = length - 1; j > 0; j--) {
                swap(&buffer[j], &buffer[j - 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void output(int *data, int length) {
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", data[i]);
        } else {
            printf("%d ", data[i]);
        }
    }
}

