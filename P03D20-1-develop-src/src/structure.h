#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Polish_notation* add(double num, char oper, struct Polish_notation* elem);
void free_formula(struct Polish_notation** polish_formula);

struct Stack* push(char chr, struct Stack* top);
struct Stack* pop(struct Stack* top, char* chr);
void mult_pop(struct Stack** operators, struct Polish_notation** polish_formula);

struct Calc_stack* push_calc(double number, struct Calc_stack* top);
struct Calc_stack* pop_calc(struct Calc_stack* top, double* num);

struct Polish_notation {
    double number;
    char operator;
    struct Polish_notation* next;
};

struct Stack {
    char value;
    struct Stack* prev;
};

struct Calc_stack {
    double value;
    struct Calc_stack* prev;
};

#endif