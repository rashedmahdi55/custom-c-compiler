// function prototypes

// tokenization functions
int scan(struct token *t);

// parsing functions
// AST node generators
struct astNode *mkAstNode(int op, struct astNode *left, struct astNode *right, int intValue);
struct astNode *mkAstLeafNode(int op, int intValue);
struct astNode *mkAstUnaryNode(int op, struct astNode *left, int intValue);

// binary tree generator
struct astNode *binExpr(void);

// AST tree interpreter
int interpretAst(struct astNode *node);