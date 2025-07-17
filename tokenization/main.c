#include "def.h"

#define extern_ 
#include "data.h"
#undef extern_

#include "pro.h"

// setting up initial condition
void init(void)
{
	Line = 1;
	Putback = '\n';
}

// program usage msg, incase run incorrectly 
void usage(char* prog)
{
	fprintf(stderr, "usage: %s [inFile]\n", prog);
}
char* tokens[] = {"T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_NUM"};

// prints tokens to the console
void tokenize(void)
{
	struct token t;


	while(scan(&t))
	{
		printf("token: %s", tokens[t.token]);

		if (t.token == T_NUM)
		{
			printf(", value: %d", t.value);
		}

		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	// checks correct number of arguments
	if (argc != 2)
	{
		usage(argv[0]);
		exit (1);
	}

	// setting up initial condition
	init();

	InFile = fopen(argv[1], "r");

	// error in opening file
	if (InFile == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit (1);
	}

	// tokenization
	tokenize();

}
