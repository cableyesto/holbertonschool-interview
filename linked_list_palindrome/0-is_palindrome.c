#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - Reverses a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: A pointer to the head of the linked list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half, *first_half;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (1); /* Empty or single element list is a palindrome. */
	}

	/* Use the fast and slow pointer technique to find the middle. */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse the second half of the list. */
	second_half = reverse_list(slow);
	first_half = *head;

	/* Compare the first half and the reversed second half. */
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			return (0);
		}

		first_half = first_half->next;
		second_half = second_half->next;
	}

	return (1);
}
