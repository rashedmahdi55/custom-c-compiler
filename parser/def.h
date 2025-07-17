#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// structure and enum definition

enum
{
	T_PLUS, T_MINUS, T_SLASH, T_STAR, T_NUM
};

struct token 
{
	int token;
	int value;
};
