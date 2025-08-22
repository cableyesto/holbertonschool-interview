#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * get_insertion_parent - Finds the first node missing a child (BFS)
 * @root: pointer to the root node
 * Return: Parent node where the new node should be inserted
 */
heap_t *get_insertion_parent(heap_t *root)
{
	int front = 0, rear = 0;
	heap_t **queue = malloc(sizeof(heap_t *) * 1024);

	if (queue == NULL)
		return (NULL);

	queue[rear++] = root; /* Enqueue root */

	while (front < rear)
	{
		heap_t *current = queue[front++]; /* Dequeue */

		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}

		if (current->left)
			queue[rear++] = current->left; /* Enqueue left child */
		if (current->right)
			queue[rear++] = current->right; /* Enqueue right child */
	}

	free(queue);
	return (NULL);
}

/**
 * heapify_up - Bubbles up a node to maintain Max Heap property
 * @node: Node to move if necessary
 * Return: The final node after bubbling (contains inserted value)
 */
heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;

		/* Swap node memory allocation, not just the values */
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = get_insertion_parent(*root);
	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
