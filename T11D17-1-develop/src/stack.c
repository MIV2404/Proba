#include "stack.h"

// инициализация
struct elem* init(int val) {
    struct elem* head = (struct elem*)malloc(sizeof(struct elem));
    head->val = val;
    head->next = NULL;
    return head;
}

// добавление элемента в стек
void push(struct elem** head, int val) {
    struct elem* tmp = (struct elem*)malloc(sizeof(struct elem));
    tmp->val = val;
    tmp->next = *head;
    *head = tmp;
}

// получение элемента из стека
int pop(struct elem** head) {
    struct elem* tmp = *head;
    int value = (*head)->val;
    *head = (*head)->next;
    free(tmp);
    return value;
}

// очистка стека
void destroy(struct elem** head) {
    struct elem* tmp = *head;
    while (*head != NULL) {
        free(tmp);
        *head = (*head)->next;
        tmp = *head;
    }
}
