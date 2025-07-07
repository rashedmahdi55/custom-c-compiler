#include "defs.h"
#include "data.h"
#include "decl.h"

// gets the next char from input stream
static int next(void)
{
    int c;

    if (putback)        // checks whether there was a char put away
    {
        c = putback;
        putback = 0;

        return c;
    }

    c = fgetc(inFile);  // gets char from input stream

    if (c == '\n')
    {
        line++;
    }

    return c;
}

// skips input char's we don't need
// exa: white space, newline, tab etc.
static int skip(void)
{
    int c;
    c = next();

    while(c == ' ' || c == '\n' || c == '\t')   // parses char until valid char is found
    {
        c = next();
    }

    return c;
}

// puts back unwanted char back in the input stream
static void putbackChar(int c)
{
    putback = c;
}

// finds char position in a string
static int chrpos(char* s, int c)
{
    char * p;
    p = strchr(s, c);

    return (p ? p - s : - 1);
}

// scans an integer token and extracts its value
static int scanInt(int c)
{
    int k, val = 0;

    while((k = chrpos("0123456789", c)) >= 0)       // parses the whole integer value
    {
        val = val * 10 + k;
        c = next();
    }

    // hits a non integer char

    putbackChar(c);         // puts it back in the input stream

    return val;
}

// scans token
int scan(struct token *t)
{
    int c;

    c = skip();     // skips unwanted char and finds a token

    switch (c)                      // token assignment
    {
        case EOF:                   // reached end of file, no token found
            return (0);
        case '+':
            t -> token = T_PLUS;
            break;
        case '-':
            t -> token = T_MINUS;
            break;
        case '*':
            t -> token = T_STAR;
            break;
        case '/':
            t -> token = T_SLASH;
            break;

        default:
            if (isdigit(c))
            {
                t -> token = T_INTLIT;
                t -> intValue = scanInt(c);
                break;
            }

            printf("Unrecognised character '%c' on line %d\n", c, line);
            exit(1);
    }

    // a token was found
    return (1);
}



