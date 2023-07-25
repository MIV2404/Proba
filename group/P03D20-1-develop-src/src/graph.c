#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "counting.h"
#include "parser.h"

#define HORIZONTAL 80
#define VERTICAL 25
#define void_sym 46
#define graph_sym 42
#define dy_ordinate 12

void fill_graph(int matrix[VERTICAL][HORIZONTAL]);
void create_graphic(int matrix[VERTICAL][HORIZONTAL], char formula[]);
void print_graph(int matrix[VERTICAL][HORIZONTAL]);

int main() {
    char formula[100];
    int flag = 0;

    fgets(formula, 100, stdin);
    for (int i = 0; formula[i] != '\0' && formula[i] != '\n'; i++) {
        if (formula[i] == 'x') {
            flag = 1;
        }
    }
    if (flag) {
        int graph[VERTICAL][HORIZONTAL];
        fill_graph(graph);
        create_graphic(graph, formula);
        print_graph(graph);
    } else {
        printf("n/a");
    }
    return flag;
}

void fill_graph(int matrix[VERTICAL][HORIZONTAL]) {
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZONTAL; j++) {
            matrix[i][j] = void_sym;
        }
    }
}

void create_graphic(int matrix[VERTICAL][HORIZONTAL], char formula[]) {
    int count = 0;
    for (double x = 0; x <= 4.0 * M_PI; x += 4.0 * M_PI / 80.0) {
        double res = parsing(formula, x);
        int y = round(res * dy_ordinate);
        if (y <= dy_ordinate && y >= -dy_ordinate) {
            matrix[dy_ordinate + y][count] = graph_sym;
        }
        count++;
    }
}

void print_graph(int matrix[VERTICAL][HORIZONTAL]) {
    for (int rows = 0; rows < VERTICAL; rows++) {
        for (int cols = 0; cols < HORIZONTAL; cols++) {
            printf("%c", matrix[rows][cols]);
        }
        printf("\n");
    }
}
