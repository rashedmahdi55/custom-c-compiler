#include "def.h"
#include "data.h"
#include "pro.h"

// gets char from the file / putback input stream
static int getChar(void)
{
	int c;

	// checks if a char was put back in in the input stream
	if (Putback)
	{
		c = Putback;
		Putback = 0;

		return c;
	}

	// gets char from the file
	c = fgetc(InFile);

	if (c == '\n')
	{
		Line++;
	}

	return c;
}

// skips unwanted input
static int skip(void)
{
	int c; 
	c = getChar();

	while(c == '\n' || c == '\t' || c == ' ')
	{
		c = getChar();
	}

	return c;
}

// finds position of char in a string
static int chrPos(char* str, int ch)
{
	char* pos;
	pos = strchr(str, ch);

	return (pos ? pos - str : -1);
}

// puts back a char back in the input stream
static void putBack(int c)
{
	Putback = c;
}

// scans a whole integer from input
static int scanInt(int c)
{
	int val = 0, k;
	while ((k = chrPos("0123456789", c)) >= 0)
	{
		val *= 10;
		val += k;
		c = getChar();
	}

	// found a non-integer char
	// put it back in the input stream
	putBack(c);

	return val;
}

// scans a token and populates its attributes
int scan(struct token *t)
{
	int c;
	c = skip();

	switch(c)
	{
		case EOF:
			// no token was found
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
			// checks if the token is a integer
			if (isdigit(c))
			{
				t -> token = T_NUM;
				t -> value = scanInt(c);
				break;
			}

			// unrecognized char
			// fprintf(stderr, "Unexpected token '%c' on line %d\n", c, Line);
			printf("Unexpected token '%c' on line %d\n", c, Line);

			// immediate exit with error
			exit (1);
	}

	// a token was found
	return (1);
}
