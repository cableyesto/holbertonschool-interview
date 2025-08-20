#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node in a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: adress of the new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *ptr_to_keep;
    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
	return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
	*head = new;
    else
    {
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	ptr_to_keep = current->next;
	new->next = ptr_to_keep;
	current->next = new;
    }

    return (new);
}
