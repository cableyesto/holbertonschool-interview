#include <stdio.h>
#include "palindrome.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/**
 * is_palindrome - Checks whether or not a given unsigned integer is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if the integer is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	if (n < 10) return (1);

	unsigned long divisor = 1;
	unsigned long temp = n;

	// Step 1: Find the divisor (10^(num_digits - 1))
	while (temp >= 10) {
		temp /= 10;
		divisor *= 10;
	}

	while (n >= 10) {
		int left = n / divisor;
		int right = n % 10;

		if (left != right)
			return 0;

		// Remove first and last digits
		n = (n % divisor) / 10;

		// Shrink divisor by 2 digits
		divisor /= 100;
	}

	return 1;
}
