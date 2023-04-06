#include "main.h"

int _strlen_recursion(char *str)
{
	if (!*str)
	{
		return (0);
	}
	return (1 + _strlen_recursion(++str));
}

int p1(char *str, int pos)
{
	if (pos < 1)
	{
		return (1);
	}

	if (*str == *(str + pos))
	{
		return (p1(str + 1, pos - 2));
	}
	return (0);
}

int is_palindrome(char *str)
{
	int len = _strlen_recursion(str);

	return (p1(str, len - 1));
}

