#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to list to be freed
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *current;
	listint_t *head;
	int res = 0;

	if (list == NULL)
		return (res);

	head = list;
	current = list;

	if (current->next == NULL)
		return (res);

	do {
		if (current->next == head)
		{
			res = 1;
			return (res);
		}
		current = current->next;
	} while (current->next != NULL);

	return (res);
}
