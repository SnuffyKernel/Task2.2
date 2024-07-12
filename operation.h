#ifndef OPERATION_H
#define OPERATION_H

int add(int a, int b);
int diff(int a, int b); 
int mult(int a, int b); 
int divis(int a, int b);
int isOperation(char symb);
int getOp(char op, int a, int b); 

typedef int (*operation)(int, int);

struct Operation {
    char operator;
    operation op;
};

#define SIZE_OP (sizeof(operations) / sizeof(struct Operation))

#endif //OPERATION_H