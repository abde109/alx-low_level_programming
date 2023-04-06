#include "main.h"

int _sqrt_recursion(int num)
{
	return (_sqrt(num, 1));
}

int _sqrt(int num, int i)
{
	if (num < 0)
	{
		return (-1);
	}
	if ((i * i) > num)
	{
		return (-1);
	}
	if (i * i == num)
	{
		return (i);
	}
	return (_sqrt(num, i + 1));
}

