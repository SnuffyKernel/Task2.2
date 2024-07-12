#include "parser.h"

STACK_TYPE(char, CharStack)
STACK_TYPE(int, IntStack)

void addOperations(char *dest, struct CharStack *stack, int *n)
{
    for (int i = 0; i <= stack->top; i++)
    {
        dest[(*n)++] = stack->data[i];
    }
    stackInit_CharStack(stack);
}

void checkBrack(char *str, char *dest, int *i, int *j)
{
    char newDest[MAX_SIZE];
    char newStr[MAX_SIZE];
    int k = 0;
    ++(*i);
    for (int checkBrack = 1; checkBrack; (*i)++, k++)
    {
        newStr[k] = str[(*i)];
        if (str[(*i)] == '(')
            checkBrack++;
        if (checkBrack && str[(*i)] == ')')
            checkBrack--;
    }
    newStr[k - 1] = '\0';
    parser(newStr, newDest);

    for (k = 0; newDest[k] != '\0'; k++, (*j)++)
    {
        dest[(*j)] = newDest[k];
    }
}

void parser(char *str, char *dest)
{
    struct CharStack stack;
    stackInit_CharStack(&stack);

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
                checkBrack(str, dest, &i, &j);

                if (str[i] == '\0')
                    break;
            }
        }

        int op = isOperation(str[i]);

        if (op)
        {
            if (stackEmpt_CharStack(&stack))
            {
                stackPush_CharStack(&stack, str[i]);
            }
            else
            {
                int last_op = isOperation(stackPeek_CharStack(&stack));
                if (op > last_op)
                {
                    last_op = stackPeek_CharStack(&stack);
                    stackPop_CharStack(&stack);

                    stackPush_CharStack(&stack, str[i]);
                    stackPush_CharStack(&stack, last_op);
                }
                else if (op <= last_op)
                {
                    addOperations(dest, &stack, &j);
                    stackPush_CharStack(&stack, str[i]);
                }
                else
                {
                    stackPush_CharStack(&stack, str[i]);
                }
            }
        }
    }

    addOperations(dest, &stack, &j);
    dest[j] = '\0';
}

int count(char *str)
{
    char dest[MAX_SIZE];
    parser(str, dest);

    struct IntStack stack;
    stackInit_IntStack(&stack);

    for (int i = 0; dest[i] != '\0'; i++)
    {
        if (isdigit(dest[i]))
        {
            stackPush_IntStack(&stack, dest[i] - 48);
        }
        else
        {
            if (!stackEmpt_IntStack(&stack))
            {
                int b = stackPeek_IntStack(&stack);
                stackPop_IntStack(&stack);
                int a = stackPeek_IntStack(&stack);
                stackPop_IntStack(&stack);
                stackPush_IntStack(&stack, getOp(dest[i], a, b));
            }
        }
    }

    return stackPeek_IntStack(&stack);
}