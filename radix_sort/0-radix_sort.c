#include <stdlib.h>
#include "sort.h"

/**
 * get_max - finds the maximum value in an array
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_digit - performs counting sort based on a digit
 * @array: array to sort
 * @size: size of the array
 * @exp: current digit exponent
 * @output: temporary array
 */
void counting_sort_digit(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	int i;

	for (i = 0; (size_t)i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; (size_t)i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array using LSD radix sort
 * @array: array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
