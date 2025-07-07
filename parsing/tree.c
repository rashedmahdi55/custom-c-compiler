#include "defs.h"
#include "data.h"
#include "decl.h"

// creates and returns generic AST node
struct astNode *mkAstNode(int op, struct astNode *left, struct astNode *right, int intValue)
{
    struct astNode *node;

    node = (struct astNode *)malloc(sizeof(struct astNode)); // checking memory allocation

    if (node == NULL)
    {
        fprintf(stderr, "Unable to malloc in mkAstNode()\n");
        exit(1);
    }

    node -> op = op; // populating node attributes

    node -> left = left;
    node -> right = right;

    node -> intValue = intValue;

    return node;
}

// creates and returns a leaf node
struct astNode *mkAstLeafNode(int op, int intValue)
{
    return mkAstNode(op, NULL, NULL, intValue);
}

// creates a unary AST node: only one child
struct astNode *mkAstUnaryNode(int op, struct astNode *left, int intValue)
{
    return mkAstNode(op, left, NULL, intValue);
}