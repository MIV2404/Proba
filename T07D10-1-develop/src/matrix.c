#include <stdio.h>
#include <stdlib.h>

#define ROWS 100
#define COLS 100

int input_algo(int* row, int* col, int* select);
int input_matrix(int* row, int* col);

void algo_1(const int col, const int row, int (*d_data)[COLS]);
void algo_2(const int row, const int col);
void algo_3(const int row, const int col);
void algo_4(const int row, const int col);

void output_for_algo_1(const int col, const int row, int (*d_data)[COLS]);
void output(const int row, const int col, int** data);

int main() {
    int row, col, select;

    if (input_algo(&row, &col, &select) == 0) {
        printf("n/a");
    } else {
        int d_data[ROWS][COLS];
        switch (select) {
            case 1:
                algo_1(col, row, d_data);
                break;
            case 2:
                algo_2(row, col);
                break;
            case 3:
                algo_3(row, col);
                break;
            case 4:
                algo_4(row, col);
                break;
        }
    }
    return 0;
}

void output(const int row, const int col, int** data) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", data[i][j]);
            } else {
                printf("%d ", data[i][j]);
            }
        }
        printf("\n");
    }
}
void output_for_algo_1(const int col, const int row, int (*d_data)[COLS]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", d_data[i][j]);
            } else {
                printf("%d ", d_data[i][j]);
            }
        }
        printf("\n");
    }
}
int input_algo(int* row, int* col, int* select) {
    int result = 1;
    char endl;

    if (scanf("%d%c", select, &endl) != 2 || endl != '\n') {
        result = 0;
    } else if (input_matrix(row, col) == 0) {
        result = 0;
    }
    return result;
}
int input_matrix(int* row, int* col) {
    const int matrix_2d = 2;
    char endl;
    int result = 1;

    for (int i = 0; i < matrix_2d; i++) {
        if (i == matrix_2d - 1) {
            if (scanf("%d%c", col, &endl) != 2 || endl != '\n') {
                result = 0;
            }
        } else {
            if (scanf("%d", row) != 1) {
                result = 0;
            }
        }
    }

    return result;
}
void algo_1(const int col, const int row, int (*d_data)[COLS]) {
    char endl;
    int result = 1;

    if (col <= 0 || row <= 0 || col > 100 || row > 100) {
        printf("n/a");
        return;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                if (scanf("%d%c", &d_data[i][j], &endl) != 2 || endl != '\n') {
                    result = 0;
                }
            } else {
                if (scanf("%d", &d_data[i][j]) != 1) {
                    result = 0;
                }
            }
        }
    }

    if (result) {
        output_for_algo_1(col, row, d_data);
    } else {
        printf("n/a");
    }
}
void algo_2(const int row, const int col) {
    int result = 1;

    int** single_array_matrix = malloc(row * col * sizeof(int) + row * sizeof(int*));
    int* ptr = (int*)(single_array_matrix + row);
    for (int i = 0; i < row; i++) single_array_matrix[i] = ptr + col * i;

    char endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                if (scanf("%d%c", &single_array_matrix[i][j], &endl) != 2 || endl != '\n') {
                    result = 0;
                }
            } else {
                if (scanf("%d", &single_array_matrix[i][j]) != 1) {
                    result = 0;
                }
            }
        }
    }

    if (result) {
        output(row, col, single_array_matrix);
    } else {
        printf("n/a");
    }

    free(single_array_matrix);
}
void algo_3(const int row, const int col) {
    int result = 1;

    int** pointer_array = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) pointer_array[i] = malloc(col * sizeof(int*));

    char endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                if (scanf("%d%c", &pointer_array[i][j], &endl) != 2 || endl != '\n') {
                    result = 0;
                }
            } else {
                if (scanf("%d", &pointer_array[i][j]) != 1) {
                    result = 0;
                }
            }
        }
    }

    if (result) {
        output(row, col, pointer_array);
    } else {
        printf("n/a");
    }

    for (int i = 0; i < row; i++) free(pointer_array[i]);

    free(pointer_array);
}
void algo_4(const int row, const int col) {
    int result = 1;

    int** pointer_array = malloc(row * sizeof(int));
    int* values_array = malloc(row * col * sizeof(int));

    for (int i = 0; i < row; i++) pointer_array[i] = values_array + col * i;

    char endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                if (scanf("%d%c", &pointer_array[i][j], &endl) != 2 || endl != '\n') {
                    result = 0;
                }
            } else {
                if (scanf("%d", &pointer_array[i][j]) != 1) {
                    result = 0;
                }
            }
        }
    }

    if (result) {
        output(row, col, pointer_array);
    } else {
        printf("n/a");
    }

    free(values_array);
    free(pointer_array);
}