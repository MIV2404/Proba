#include <stdio.h>
#include <stdlib.h>

int array_size();
int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = array_size();  // размер массива
    int *data = NULL;
    if (n != -1) {
        data = (int *)calloc(n, sizeof(int));  // аллоцируем память:
        if (data != NULL) {
            if (input(data, n) != 1) {
                sort(data, n);
                output(data, n);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(data);  // очищаем память
    return 0;
}

// определяем размер массива:
int array_size() {
    int n;
    char end;
    if (!(scanf("%d%c", &n, &end) == 2 && end == '\n' && n > 0)) {
        n = -1;
    }
    return n;
}

// функция, заполняющая массив данными:
int input(int *a, int n) {
    int flag = 0;  // ok

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (!(getchar() == '\n' || getchar() == EOF)) {
        flag = 1;  // ошибка!!
    }

    return flag;
}

// функция, сортировки пузырьком:
void sort(int *buffer, int length) {
    int p;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (buffer[j] > buffer[j + 1]) {
                p = buffer[j];
                buffer[j] = buffer[j + 1];
                buffer[j + 1] = p;
            }
        }
    }
}

// функция вывода:
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != (n - 1)) {
            printf(" ");
        }
    }
}
