#include "main.h"

int _strlen_recursion(char *str)
{
	if (!*str)
	{
		return (0);
	}
	return (1 + _strlen_recursion(++str));
}

