#include "stack.h"

#include <stdio.h>

void test();

int main() { test(); }

void test() {
    // тест инициализации
    struct elem* head = init(777);
    printf("1. Инициализация стека\n");
    printf("\t- Ожидаемое значение:\t777\n");
    printf("\t- Реальное значение:\t%d\n", head->val);
    printf("\t- Результат теста:");
    if (head->val == 777)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    // тест добавления элемента в стек
    push(&head, -123);
    printf("2. Функция push\n");
    printf("\t- Ожидаемое значение:\t-123\n");
    printf("\t- Реальное значение:\t%d\n", head->val);
    printf("\t- Результат теста:");
    if (head->val == -123)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    // тест вызова из стека
    int res = pop(&head);
    printf("3. Функция pop\n");
    printf("\t- Ожидаемый результат pop:\t-123\n");
    printf("\t- Реальный результат pop:\t%d\n", res);
    printf("\t- Ожидаемая верхушка после pop:\t777\n");
    printf("\t- Реальная верхушка после pop:\t%d\n", head->val);
    printf("\t- Результат теста:");

    if (head->val == 777 && res == -123)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");

    // очистка стека
    destroy(&head);
}
