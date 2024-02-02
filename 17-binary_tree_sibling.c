#include "binary_trees.h"
/**
 * binary_tree_sibling - function
 * @node: pointer
 * Return: pointer
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return ((node->parent->right == node) ?
			node->parent->left : node->parent->right);
}
