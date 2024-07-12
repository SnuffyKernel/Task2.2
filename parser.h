#ifndef PARSER_H
#define PARSER_H

#include <ctype.h>
#include "operation.h"
#include "stack.h"

void checkBrack(char *str, char *dest, int *i, int *j);
void parser(char *str, char *dest);
int count(char *dest);

#endif