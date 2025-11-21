#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * find_express_range - Traverse the express lane to find search range
 *
 * @head: Pointer to the start node
 * @value: Value to search for
 * @range_start: Pointer to store lower bound node
 *
 * Return: Upper bound node (NULL if not found through express lane)
 */
skiplist_t *find_express_range(skiplist_t *head, int value,
			       skiplist_t **range_start)
{
	skiplist_t *node = head;
	skiplist_t *prev = NULL;

	while (node->express)
	{
		prev = node;
		node = node->express;

		printf("Value checked at index [%lu] = [%d]\n",
				node->index, node->n);

		if (node->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					prev->index, node->index);
			*range_start = prev;
			return (node);
		}
	}

	*range_start = node;
	return (NULL);
}

/**
 * linear_skip - Search in a sorted skip list of integers
 * @head: Pointer to the head node of the list
 * @value: Value to search for
 *
 * Return: pointer to first node containing value (NULL if not found)
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *start = NULL, *end = NULL, *node = NULL;

	if (!head)
		return (NULL);

	if (head->n == value)
		return (head);

	end = find_express_range(head, value, &start);

	if (!end)
	{
		end = start;
		while (end->next)
			end = end->next;

		printf("Value found between indexes [%lu] and [%lu]\n",
				start->index, end->index);
	}

	for (node = start; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				node->index, node->n);

		if (node->n == value)
			return (node);
	}

	return (NULL);
}
