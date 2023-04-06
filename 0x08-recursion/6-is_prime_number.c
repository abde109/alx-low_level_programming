#include "main.h"

int tmp_prime(int num, int i);

int divisors(int n, int m)
{
	if (m % n == 0)
	{
		return (0);
	}
	else if (m / 2 > n)
	{
		return (divisors(n + 2, m));
	}
	else
	{
		return (1);
	}
}

int is_prime_number(int num)
{
	if ((!(num % 2) && num != 2) || num < 2)
	{
		return (0);
	}
	else
	{
		return (divisors(3, num));
	}
}

