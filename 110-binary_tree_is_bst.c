#include "binary_trees.h"

/**
 * bst_compare_right - check
 * @tree: node
 * @start: value
 * Return: 1 if all right nodes are greater than `start_val`, 0 otherwise
 */
int bst_compare_right(const binary_tree_t *tree, int start)
{
	if (tree == NULL)
		return (1);
	if (tree->n > start)
		return (bst_compare_right(tree->right, start)
			&& bst_compare_right(tree->left, start));
	return (0);
}

/**
 * bst_compare_left - check
 * @tree: node
 * @start: value
 * Return: 1 if all left nodes are less than `start_val`, 0 otherwise
 */
int bst_compare_left(const binary_tree_t *tree, int start)
{
	if (tree == NULL)
		return (1);
	if (tree->n < start)
		return (bst_compare_left(tree->left, start)
			&& bst_compare_left(tree->right, start));
	return (0);
}

/**
 * binary_tree_is_bst - check
 * @tree: root
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (bst_compare_left(tree->left, tree->n)
		&& bst_compare_right(tree->right, tree->n))
		return ((tree->left == NULL
			 || binary_tree_is_bst(tree->left))
			&& (tree->right == NULL
				|| binary_tree_is_bst(tree->right)));
	return (0);
}
