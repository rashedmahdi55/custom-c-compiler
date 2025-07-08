#include "defs.h"
#include "data.h"
#include "decl.h"


// list of AST operations
static char* astOp[] = {"+", "-", "*", "/"};

int interpretAst(struct astNode *node, int sp)
{
    int leftVal, rightVal;

    for(int i = 0; i < sp; i++)
    {
        printf("_");
    }

    switch(node -> op)
    {
        case A_INTLIT:
            printf("(%d)", node -> intValue);
            break;
        case A_ADD:
            printf("(+)");
            break;
        case A_SUB:
            printf("(-)");
            break;
        case A_MUL:
            printf("(*)");
            break;
        case A_DIV:
            printf("(/)");
            break;
        default:
            break;
    }

    printf("\n");

    // recursively extracts left value
    if (node -> left)
    {
        leftVal = interpretAst(node -> left, sp + 2);
    }

    // recursively extracts right value
    if (node -> right)
    {
        rightVal = interpretAst(node -> right, sp + 2);
    }



    // debugging: printing each int literal and opeartions to be performed
    // if (node -> op == A_INTLIT)
    // {
    //     printf("int %d\n", node -> intValue);
    // }
    // else
    // {
    //     printf("%d %s %d\n", leftVal, astOp[node -> op], rightVal);
    // }

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
            if (rightVal == 0)
            {
                fprintf(stderr, "Error: division by zero\n");
                exit(1);
            }
            return (leftVal / rightVal);

        case A_INTLIT:                          // base case for recursive call
            return (node -> intValue);
            
        default:
            fprintf(stderr, "Unknown AST operation on line %d\n", line);
            exit(1);
    }
}
