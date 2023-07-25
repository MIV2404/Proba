#include "counting.h"

#include <math.h>
#include <stdlib.h>

double polish_calc(struct Polish_notation** polish_notation) {
    struct Calc_stack* calculation = NULL;
    struct Polish_notation** temp = polish_notation;
    while (*polish_notation != NULL) {
        if ((*polish_notation)->number != -1) {
            calculation = push_calc((*polish_notation)->number, calculation);
        } else if ((*polish_notation)
                       ->
                       operator== '+' ||(*polish_notation)
                       ->
                       operator== '*' ||(*polish_notation)
                       ->
                       operator== '/') {
            calculation = extract_X_Y(calculation, polish_notation);
        } else if ((*polish_notation)
                       ->
                       operator== 'S' ||(*polish_notation)
                       ->
                       operator== 'C' ||(*polish_notation)
                       ->
                       operator== 'T' ||(*polish_notation)
                       ->
                       operator== 'G' ||(*polish_notation)
                       ->
                       operator== 'L' ||(*polish_notation)
                       ->
                       operator== 's') {
            calculation = extract_X(calculation, polish_notation);
        } else if ((*polish_notation)->operator== '-') {
            if (calculation->prev != NULL) {
                calculation = extract_X_Y(calculation, polish_notation);
            } else {
                calculation = extract_unary_X(calculation);
            }
        }
        *polish_notation = (*polish_notation)->next;
    }
    double result = calculation->value;
    free_formula(temp);
    free(calculation);
    return result;
}

struct Calc_stack* extract_X_Y(struct Calc_stack* calculation, struct Polish_notation** polish_notation) {
    double x, y;
    calculation = pop_calc(calculation, &x);
    calculation = pop_calc(calculation, &y);
    double result = bin_oper(x, y, (*polish_notation)->operator);
    calculation = push_calc(result, calculation);
    return calculation;
}

struct Calc_stack* extract_X(struct Calc_stack* calculation, struct Polish_notation** polish_notation) {
    double x;
    calculation = pop_calc(calculation, &x);
    double result = un_oper(x, (*polish_notation)->operator);
    calculation = push_calc(result, calculation);
    return calculation;
}

struct Calc_stack* extract_unary_X(struct Calc_stack* calculation) {
    double x;
    calculation = pop_calc(calculation, &x);
    double result = x * -1;
    calculation = push_calc(result, calculation);
    return calculation;
}

double bin_oper(double x, double y, char operator) {
    double result = 0;
    if (operator== '+') {
        result = x + y;
    } else if (operator== '-') {
        result = y - x;
    } else if (operator== '*') {
        result = x * y;
    } else if (operator== '/') {
        result = y / x;
    }
    return result;
}

double un_oper(double x, char operator) {
    double result = 0;
    if (operator== 'S') {
        result = sin(x);
    } else if (operator== 'C') {
        result = cos(x);
    } else if (operator== 'T') {
        result = tan(x);
    } else if (operator== 'G') {
        result = cos(x) / sin(x);
    } else if (operator== 'L') {
        result = log(x);
    } else if (operator== 's') {
        result = sqrt(x);
    }
    return result;
}
