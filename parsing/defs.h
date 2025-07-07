#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// definitions for tokenization
// tokens
enum
{
    T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// token structure
struct token
{
    int token;
    int intValue;
};


// definitions for generating Abstract Syntax Trees
// AST nodes
enum
{
    A_ADD, A_SUB, A_MUL, A_DIV, A_INTLIT
};

// AST structure
struct astNode
{
    int op;     // operation to be performed;

    struct astNode *left;   // left child node
    struct astNode *right;   // right child node

    int intValue;       // in case of integer literal
};
