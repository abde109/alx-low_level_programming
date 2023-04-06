#include "main.h"

int _pow_recursion(int base, int exponent)
{
	if (exponent < 0)
	{
		return (-1);
	}
	if (exponent == 0)
	{
		return (1);
	}
	return (base * _pow_recursion(base, exponent - 1));
}

