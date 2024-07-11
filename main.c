#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    char data[MAX_SIZE];
    int top;
};

void stackInit(struct Stack* stack) {
    stack->top = -1;
}

int stackEmpt(struct Stack* stack){
    return stack->top == -1 ? 1 : 0;
}

int stackFull(struct Stack* stack){
    return stack->top == MAX_SIZE - 1 ? 1 : 0;
}

void stackPush(struct Stack* stack, char symb) {
    if ( !stackFull(stack) ) {
        stack->data[ ++(stack->top)] = symb;
    }
}

void stackPop(struct Stack* stack) {
    if ( !stackEmpt(stack) ) {
        --(stack->top);
    }
}

char stackPeek(struct Stack* stack) {
    if ( !stackEmpt(stack) )
        return stack->data[ stack->top ] ;
    else return 0;
}

int isOperation(char symb) {
    if (symb == '+' || symb == '-') return 1;
    if (symb == '*' || symb == '/') return 2;
    if (symb == '(') return 3;
    return 0;
}

void addOperations(char *dest, struct Stack *stack, int* n)
{
    for (int i = 0; i <= stack->top; i++)
    {
        dest[(*n)++] = stack->data[i];
    }
    stackInit(stack);
}

void parser(struct Stack *stack, char *str, char *dest)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            dest[j++] = str[i];
        }
        else
        {
            if (str[i] == '(')
            {
                struct Stack newStack;
                stackInit(&newStack);
                char newDest[MAX_SIZE];
                char newStr[MAX_SIZE];
                i++;
                for (int checkBrack = 0, k = 0; str[i] != ')' && !checkBrack; i++, k++) {
                    newStr[k] = str[i];
                    if (str[i] == '(') checkBrack++;
                    if (checkBrack && str[i] == ')') checkBrack--;
                }
                parser(&newStack, newStr, newDest);

                strcat(dest, newDest);
                i = strlen(dest) - 2;
            }

            if (str[i] == ')') continue;
        }

        int op = isOperation(str[i]);

        if (op)
        {
            if (stackEmpt(stack))
            {
                stackPush(stack, str[i]);
            }
            else
            {
                int last_op = isOperation(stack->data[stack->top]);
                if (op > last_op)
                {
                    last_op = stackPeek(stack);
                    stackPop(stack);

                    stackPush(stack, str[i]);
                    stackPush(stack, last_op);
                }
                else if (op <= last_op)
                {
                    addOperations(dest, stack, &j);
                    stackPush(stack, str[i]);
                }
                else
                {
                    stackPush(stack, str[i]);
                }
            }
        }
    }

    addOperations(dest, stack, &j);
    dest[j] = '\0';
}

int main () {
    struct Stack stack;
    stackInit(&stack);
    
    char dest[MAX_SIZE];
    char str[MAX_SIZE];

    scanf("%s", str);

    parser(&stack,str,dest);
    printf("%s", dest);

    return 0;
}