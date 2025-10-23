#include <stdlib.h>
#include "slide_line.h"
#include <stdio.h>


/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to an array of integer
 * @size: number of element in @line array
 * @direction: pointer to an array of integer
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (EXIT_FAILURE);

	if (size == 1)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (line[i] == 0)
			{
				size_t idx_first_non_zero = i;

				do {
					idx_first_non_zero++;
				} while (line[idx_first_non_zero] == 0 && idx_first_non_zero < size);

				size_t idx_second_non_zero = idx_first_non_zero;

				do {
					idx_second_non_zero++;
				} while (line[idx_second_non_zero] == 0 && idx_first_non_zero < size);

				if (idx_first_non_zero >= size)
					break;

				if (idx_first_non_zero >= size - 1)
				{
					line[i] = line[idx_first_non_zero];
					line[idx_first_non_zero] = 0;
				} else
				{
					line[i] = line[idx_first_non_zero] + line[idx_second_non_zero];
					line[idx_first_non_zero] = 0;
					line[idx_second_non_zero] = 0;
				}
			} else
			{
				size_t idx = i;

				do {
					idx++;
				} while (line[idx] == 0);

				int cur = line[i];
				int next = line[idx];
				int merge = next + cur;

				line[i] = merge;
				line[idx] = 0;
			}
		}
	}

	if (direction == SLIDE_RIGHT)
	{
		for (size_t i = size - 1; i > 0; i--)
		{
			if (line[i] == 0)
			{
				size_t idx_first_non_zero = i;

				do {
					idx_first_non_zero--;
				} while (line[idx_first_non_zero] == 0 && idx_first_non_zero < size);

				size_t idx_second_non_zero = idx_first_non_zero;

				do {
					idx_second_non_zero--;
				} while (line[idx_second_non_zero] == 0 && idx_first_non_zero < size);

				// if (idx_first_non_zero >= size)
				// 	break;

				if (idx_first_non_zero > 0)
				{
					line[i] = line[idx_first_non_zero];
					line[idx_first_non_zero] = 0;
				} else
				{
					line[i] = line[idx_first_non_zero] + line[idx_second_non_zero];
					line[idx_first_non_zero] = 0;
					line[idx_second_non_zero] = 0;
				}
			} else
			{
				size_t idx = i;

				do {
					idx--;
				} while (line[idx] == 0);

				int cur = line[i];
				int next = line[idx];
				int merge = next + cur;

				line[i] = merge;
				line[idx] = 0;
			}
			for (size_t k = 0; k < size; k++)
				printf("%d ", line[k]);
			printf("\n");
		}
	}
	return (1);
}
