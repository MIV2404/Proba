#ifndef COUNTING_H
#define COUNTING_H

#include "parser.h"
#include "structure.h"

double polish_calc(struct Polish_notation** polish_notation);
double bin_oper(double x, double y, char operation);
double un_oper(double x, char operation);
struct Calc_stack* extract_X_Y(struct Calc_stack* calculation, struct Polish_notation** polish_notation);
struct Calc_stack* extract_X(struct Calc_stack* calculation, struct Polish_notation** polish_notation);
struct Calc_stack* extract_unary_X(struct Calc_stack* calculation);

#endif