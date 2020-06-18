#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check if a given unsigned integer is a palindrome
 *
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long t, r = 0;

	t = n;

	while (t != 0)
	{
		r = r * 10;
		r = r + (t % 10);
		t = t / 10;
	}
	if (n == r)
		return (1);
	else
		return (0);
}
