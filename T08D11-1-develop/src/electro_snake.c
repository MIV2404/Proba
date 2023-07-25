#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);
/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
/*
    7 8 9
    6 1 2
    5 4 3
*/
int input_numbers(int *n, int *m);
int **init_matrix(int n, int m);
void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void delete_matrix(int **matrix, int n);

int main() {
    int n, m, err_input = 0;
    err_input = input_numbers(&n, &m);
    if (!err_input) {
        int **matrix = init_matrix(n, m);
        input(matrix, &n, &m);
        if (n != 0 && m != 0) {
            int **result = init_matrix(n, m);
            sort_vertical(matrix, n, m, result);
            output(result, n, m);
            printf("\n\n");
            sort_horizontal(matrix, n, m, result);
            output(result, n, m);
            printf("\n\n");
            delete_matrix(result, n);
        }
        delete_matrix(matrix, n);
    }
    return 0;
}
// ввод размера матрицы
int input_numbers(int *n, int *m) {
    char ch1, ch2;
    int err_input = 0;
    if (scanf("%d%c%d%c", n, &ch1, m, &ch2) != 4 || *n <= 0 || *m <= 0 || ch1 != ' ' || ch2 != '\n') {
        err_input = 1;
        printf("n/a");
    }
    return err_input;
}
// инициализация матрицы
int **init_matrix(int n, int m) {
    int **matrix = NULL;
    matrix = (int **)malloc(n * sizeof(int *));  // выделение памяти
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    return matrix;
}
// ввод матрицы
void input(int **matrix, int *n, int *m) {
    int err = 0, i, j;
    char ch;
    for (i = 0; i < *n && err == 0; i++) {
        for (j = 0; j < *m - 1 && err == 0; j++) {
            if (scanf("%d%c", &matrix[i][j], &ch) != 2 || ch != ' ') err = 1;
        }
        if (scanf("%d%c", &matrix[i][j], &ch) != 2 || ch != '\n') err = 1;
    }
    if (err == 1) {
        *n = 0;
        *m = 0;
        printf("n/a");
    }
}
// сортировка матрицы по змейкой по вертикали
void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int array[n * m], k = 0, i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[k] = matrix[i][j];
            k++;
        }
    }
    for (i = 0; i < n * m - 1; i++) {
        for (j = i + 1; j < n * m; j++) {
            if (array[i] > array[j]) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
    k = 0;
    for (j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (i = 0; i < n; i++) {
                result_matrix[i][j] = array[k];
                k++;
            }
        } else {
            for (i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = array[k];
                k++;
            }
        }
    }
}
// сортировка матрицы по змейкой по горизонтали
void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int array[n * m], k = 0, i, j, tmp;  // создание одномерного массива
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[k] = matrix[i][j];
            k++;
        }
    }
    for (i = 0; i < n * m - 1; i++) {  // сортировка выбором
        for (j = i + 1; j < n * m; j++) {
            if (array[i] > array[j]) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
    k = 0;
    for (i = 0; i < n; i++) {  // заполнение выходной матрицы
        if (i % 2 == 0) {
            for (j = 0; j < m; j++) {
                result_matrix[i][j] = array[k];
                k++;
            }
        } else {
            for (j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = array[k];
                k++;
            }
        }
    }
}
void output(int **matrix, int n, int m) {  // печать матрицы
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (j != m - 1) {  // если не последний в строке - печать с пробелом
                printf("%d ", matrix[i][j]);
            } else if (i != n - 1) {
                printf("%d\n", matrix[i][j]);
            } else {
                printf("%d", matrix[i][j]);
            }
        }
    }
}
void delete_matrix(int **matrix, int n) {  // очистка памяти
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}