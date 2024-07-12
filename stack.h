#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

#define STACK_TYPE(type, name)                           \
    struct name                                          \
    {                                                    \
        type data[MAX_SIZE];                             \
        int top;                                         \
    };                                                   \
                                                         \
    void stackInit_##name(struct name *stack)            \
    {                                                    \
        stack->top = -1;                                 \
    }                                                    \
                                                         \
    int stackEmpt_##name(struct name *stack)             \
    {                                                    \
        return stack->top == -1 ? 1 : 0;                 \
    }                                                    \
                                                         \
    int stackFull_##name(struct name *stack)             \
    {                                                    \
        return stack->top == MAX_SIZE - 1 ? 1 : 0;       \
    }                                                    \
                                                         \
    void stackPush_##name(struct name *stack, type symb) \
    {                                                    \
        if (!stackFull_##name(stack))                    \
        {                                                \
            stack->data[++(stack->top)] = symb;          \
        }                                                \
    }                                                    \
                                                         \
    void stackPop_##name(struct name *stack)             \
    {                                                    \
        if (!stackEmpt_##name(stack))                    \
        {                                                \
            --(stack->top);                              \
        }                                                \
    }                                                    \
                                                         \
    type stackPeek_##name(struct name *stack)            \
    {                                                    \
        if (!stackEmpt_##name(stack))                    \
            return stack->data[stack->top];              \
        else                                             \
            return 0;                                    \
    }

#endif // STACK_H