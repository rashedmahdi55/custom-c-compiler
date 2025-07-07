#include "defs.h"
#include "data.h"
#include "decl.h"


// list of AST operations
static char* astOp[] = {"+", "-", "*", "/"};

int interpretAst(struct astNode *node)
{
    int leftVal, rightVal;

    // recursively extracts left value
    if (node -> left)
    {
        leftVal = interpretAst(node -> left);
    }

    // recursively extracts right value
    if (node -> right)
    {
        rightVal = interpretAst(node -> right);
    }

    // debugging: printing each int literal and opeartions to be performed
    if (node -> op == A_INTLIT)
    {
        printf("int %d\n", node -> intValue);
    }
    else
    {
        printf("%d %s %d\n", leftVal, astOp[node -> op], rightVal);
    }

    // performs operation
    switch (node -> op)
    {
        case A_ADD:
            return (leftVal + rightVal);
        case A_SUB:
            return (leftVal - rightVal);
        case A_MUL:
            return (leftVal * rightVal);
        case A_DIV:
            return (leftVal / rightVal);
        case A_INTLIT:
            return (node -> intValue);
        default:
            fprintf(stderr, "Unknown AST operation on line %d\n", line);
            exit(1);
    }
}