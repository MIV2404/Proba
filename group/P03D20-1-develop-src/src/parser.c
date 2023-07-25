#include "parser.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "counting.h"

double parsing(char formula[100], double x) {
    struct Polish_notation* polish_elem = NULL;
    struct Polish_notation* temporary = NULL;
    polish_elem = add((double)-1, '0', polish_elem);
    temporary = polish_elem;
    struct Stack* operators = NULL;
    int i = 0;
    while (formula[i] != '\0' && formula[i] != '\n') {
        if (formula[i] == '(') {
            operators = push(formula[i], operators);
            i++;
        } else if (formula[i] == 'x') {
            polish_elem = add(x, '0', polish_elem);
            i++;
        } else if (formula[i] >= '0' && formula[i] <= '9') {
            char str_number[100];
            int k = 0;
            for (int j = i; formula[j] >= '0' && formula[j] <= '9'; j++) {
                str_number[k] = formula[j];
                i++, k++;
            }
            int number = atoi(str_number);
            polish_elem = add((double)number, '0', polish_elem);
        } else if (formula[i] == ')') {
            while (operators->value != '(') {
                char operator= ' ';
                operators = pop(operators, &operator);
                polish_elem = add(-1, operator, polish_elem);
            }
            char tmp = ' ';
            operators = pop(operators, &tmp);
            i++;
        } else
            i = check_operator(formula, i, &operators, &polish_elem);
    }
    mult_pop(&operators, &polish_elem);
    free(operators);
    struct Polish_notation* temp = temporary;
    temporary = temporary->next;
    free(temp);
    return polish_calc(&temporary);
}

int check_operator(const char formula[], int i, struct Stack** operators,
                   struct Polish_notation** polish_elem) {
    char sign = ' ';
    if (formula[i] == 's' && formula[i + 1] == 'i' && formula[i + 2] == 'n') {
        sign = 'S';
        i += 3;
    } else if (formula[i] == 'c' && formula[i + 1] == 'o' && formula[i + 2] == 's') {
        sign = 'C';
        i += 3;
    } else if (formula[i] == 't' && formula[i + 1] == 'a' && formula[i + 2] == 'n') {
        sign = 'T';
        i += 3;
    } else if (formula[i] == 'c' && formula[i + 1] == 't' && formula[i + 2] == 'g') {
        sign = 'G';
        i += 3;
    } else if (formula[i] == 's' && formula[i + 1] == 'q' && formula[i + 2] == 'r' && formula[i + 3] == 't') {
        sign = 's';
        i += 4;
    } else if (formula[i] == 'l' && formula[i + 1] == 'n') {
        sign = 'L';
        i += 2;
    } else if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/') {
        sign = formula[i];
        i++;
    }
    if (*operators != NULL && Priority(sign) <= Priority((*operators)->value)) {
        char operator= ' ';
        *operators = pop(*operators, &operator);
        *polish_elem = add(-1, operator, * polish_elem);
    }
    *operators = push(sign, *operators);
    return i;
}

int Priority(char symb) {
    int res = 0;
    if (symb == '+' || symb == '-')
        res = 1;
    else if (symb == '*' || symb == '/')
        res = 2;
    else if (symb == 'S' || symb == 'C' || symb == 'T' || symb == 'G' || symb == 'L')
        res = 3;
    else if (symb == 's')
        res = 4;
    return res;
}
