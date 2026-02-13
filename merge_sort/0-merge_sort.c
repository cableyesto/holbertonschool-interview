#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_subarrays - Merges two sorted subarrays
 * @array: The original array
 * @buffer: Temporary buffer
 * @left: Starting index
 * @mid: Middle index
 * @right: Ending index
 */
void merge_subarrays(int *array, int *buffer,
	size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < mid)
		buffer[k++] = array[i++];

	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive merge sort
 * @array: The array to sort
 * @buffer: Temporary buffer
 * @left: Starting index
 * @right: Ending index
 */
void merge_sort_recursive(int *array, int *buffer,
	size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, buffer, left, mid);
	merge_sort_recursive(array, buffer, mid, right);

	merge_subarrays(array, buffer, left, mid, right);
}

/**
 * merge_sort - Sorts an array using Merge Sort algorithm
 * @array: The array to sort
 * @size: Number of elements
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
