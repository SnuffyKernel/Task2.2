#include "operation.h"

struct Operation operations[] = {
    {'+', add},
    {'-', diff},
    {'*', mult},
    {'/', divis}
};

int add(int a, int b) { return a + b; }
int diff(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divis(int a, int b) { return a / b; }

int isOperation(char symb) {
    if (symb == '+' || symb == '-') return 1;
    if (symb == '*' || symb == '/') return 2;
    return 0;
}

int getOp(char op, int a, int b) {
    for (unsigned int i = 0; i < SIZE_OP; i++ ) {
        if (op == operations[i].operator) {
            return operations[i].op(a, b);
        }
    }

    return 0;
}