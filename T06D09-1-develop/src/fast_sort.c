#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void quick_sort(int *a, int n);

int main() {
    int data[NMAX];
    if (input(data)) {
        printf("n/a\n");
    } else {
        quick_sort(data, NMAX);
        output(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    char ent;
    int err = 0;

    for (int p = 0; p < NMAX; p++) {
        if (p != NMAX - 1) {
            if (scanf("%d", &a[p]) != 1) {
                err = 1;
            }
        } else if (scanf("%d%c", &a[p], &ent) != 2 || ent != '\n') {
            err = 1;
        }
    }
    return err;
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quick_sort(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0, j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];
    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        quick_sort(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        quick_sort(&mas[i], size - i);
    }
}