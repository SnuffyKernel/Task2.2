#include <stdio.h>
#include "parser.h"

int main()
{
    char str[MAX_SIZE];

    if (fgets(str, MAX_SIZE, stdin) == NULL)
    {
        printf("ERROR");
        return 1;
    }

    printf("%d\n", count(str));

    return 0;
}