#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * is_bst - checks if a tree is a valid BST
 * @tree: pointer to the root node
 * @min: minimum allowed value
 * @max: maximum allowed value
 *
 * Return: 1 if BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced - checks if a binary tree is height balanced
 * @tree: pointer to the root node
 *
 * Return: 1 if balanced, otherwise 0
 */
int is_balanced(const binary_tree_t *tree)
{
	int left_h, right_h, diff;

	if (tree == NULL)
		return (1);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);
	diff = left_h - right_h;

	if (diff > 1 || diff < -1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node
 *
 * Return: 1 if AVL, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst(tree, -2147483648, 2147483647))
		return (0);

	return (is_balanced(tree));
}
