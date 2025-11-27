#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * create_avl_node - Creates a new AVL tree node
 * @parent: Pointer to parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 * @parent: Parent of the created node
 *
 * Return: Pointer to the root of the subtree, or NULL on failure
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL from an array
 *
 * @array: A pointer to the first element of the source array
 * @size: Number of element in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
