#include "defs.h"
#include "data.h"
#include "decl.h"

// converts a token to AST operation
int tokenToAstOp(int token)
{
    switch (token)
    {
    case T_PLUS:
        return A_ADD;
    case T_MINUS:
        return A_SUB;
    case T_STAR:
        return A_MUL;
    case T_SLASH:
        return A_DIV;
    case T_INTLIT:
        return A_INTLIT;
    default:
        fprintf(stderr, "Unknown token in tokenToAstOp() on line %d\n", line);
        exit(1);
    }
}

// parses a primary factor and returns a ast node representing it
static struct astNode *primary(void)
{
    struct astNode *node;

    switch (Token.token)
    {
    case T_INTLIT:
        node = mkAstLeafNode(A_INTLIT, Token.intValue);

        // gets next token
        scan(&Token);

        return node;
        
    default:
        fprintf(stderr, "Syntax error on line %d\n", line);
        exit(1);
    }
}

struct astNode *binExpr(void)
{
    struct astNode *node, *left, *right;
    int nodeType;

    // gets the integer literal on the left
    left = primary();

    // if reached EOF, return the left node
    if (Token.token == T_EOF)
    {
        return (left);
    }

    nodeType = tokenToAstOp(Token.token);

    // gets the next token
    scan(&Token);

    // recursively gets the right node
    right = binExpr();

    // builds a tree with left and right sub-tree
    node = mkAstNode(nodeType, left, right, 0);
}
