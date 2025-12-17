#include <stdio.h>
#include "search_algos.h"

/**
 * print_remain - Prints the current subarray
 * @array: Pointer to the first element
 * @size: Number of elements
 */
void print_remain(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_recursive - Recursive binary search helper
 * @array: Pointer to the first element
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of value or -1
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_remain(array + left, right - left + 1);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (binary_recursive(array, left, mid - 1, value));
	}

	if (array[mid] > value)
		return (binary_recursive(array, left, mid - 1, value));

	return (binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Pointer to the first element
 * @size: Number of elements
 * @value: Value to search for
 *
 * Return: Index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
