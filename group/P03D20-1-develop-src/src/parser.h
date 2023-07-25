#ifndef PARSER_H
#define PARSER_H

#include "structure.h"

double parsing(char formula[100], double x);
int check_operator(const char formula[], int i, struct Stack** operators,
                   struct Polish_notation** polish_formula);
int Priority(char);

#endif