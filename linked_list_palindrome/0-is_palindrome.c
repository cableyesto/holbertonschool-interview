#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * is_sandpile_palindrome - Function to check if a sandpile is stable.
 * @head: pointer to pointer of first node of listint_t list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	unsigned int n;
	const listint_t *current_start;
	const listint_t *current_end;
	int value_1, value_2;
	int idx;

	current_start = *head;
	current_end = *head;
	n = 0;
	idx = 0;

	while (current_end != NULL)
	{
		current_end = current_end->next;
		n++;
	}
	if (n == 0)
		return (1);
	/*
	 *Traverse through the first half,
	 *check corresponding values from the other half
	*/
	while (current_start != NULL)
	{
		/* Find the corresponding node from the end */
		current_end = *head;
		for (int i = 0; i < ((int)n - idx - 1); i++)
			current_end = current_end->next;

		value_1 = current_start->n;
		value_2 = current_end->n;

		if (value_1 != value_2)
			return (0);

		current_start = current_start->next;
		idx++;
	}

	return (1);
}
