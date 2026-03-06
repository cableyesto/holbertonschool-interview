#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - adds a new node at the end of a double circular linked list
 * @list: pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	new_node->next = *list;
	new_node->prev = last;
	last->next = new_node;
	(*list)->prev = new_node;

	return (new_node);
}

/**
 * add_node_begin - adds a new node at the beginning of a double circular list
 * @list: pointer to the head of the list
 * @str: string to duplicate and store
 *
 * Return: address of the new node, or NULL if it fails
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	new_node->next = *list;
	new_node->prev = last;
	last->next = new_node;
	(*list)->prev = new_node;

	*list = new_node;

	return (new_node);
}
