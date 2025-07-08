#include "defs.h"

#define extern_             // defining extern_ makes sure, the global variable belongs to main only
#include "data.h"           // other files will inherit them as extern
#undef extern_

#include "decl.h"

// setting up initial condition
static void init(void)
{
    line = 1;
    putback = '\n'; 
}

// usage message if incorrect start
static void usage(char* prog)
{
    fprintf(stderr, "Usage: %s [inFile]\n", prog);
}


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage(argv[0]);
        exit(1);
    }

    
    init();                         // setting up initial condition

    if ((inFile = fopen(argv[1], "r")) == NULL)     // checks if the file is opened correctly
    {
        fprintf(stderr, "Unable to open: %s\n", argv[1]);
        exit(1);
    }

    // scanning primary token
    scan(&Token);

    struct astNode *node;
    node = binExpr();

    printf("result: %d\n", interpretAst(node, 0));

    exit(0);
}