#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// tokens
enum
{
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// token structure
struct token
{
    int token;
    int intValue;
};