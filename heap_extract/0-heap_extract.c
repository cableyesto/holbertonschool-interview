#include "binary_trees.h"
#include <stdlib.h>

/* Helper prototypes */
static size_t heap_size(const heap_t *tree);
static heap_t *get_last_node(heap_t *root, size_t size);
static void heapify_down(heap_t *root);

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root node
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	/* If only one node */
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size);

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}

/**
 * heap_size - Computes the size of a heap
 * @tree: Pointer to the root node
 *
 * Return: Size of the heap
 */
static size_t heap_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order
 * @root: Pointer to the root
 * @size: Number of nodes in the heap
 *
 * Return: Pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	heap_t *node = root;
	size_t path;
	size_t mask;

	path = size;
	mask = 1UL << (sizeof(size_t) * 8 - 1);

	while ((mask & path) == 0)
		mask >>= 1;
	mask >>= 1;

	while (mask > 0)
	{
		if (path & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}

	return (node);
}

/**
 * heapify_down - Restores max heap property
 * @root: Pointer to the root node
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temp;

	while (root)
	{
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;

		root = largest;
	}
}
