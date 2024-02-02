#include "binary_trees.h"
/**
 * sibling - function
 * @node: pointer
 * Return: pointer
 */
binary_tree_t *sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return ((node->parent->right == node) ?
			node->parent->left : node->parent->right);
}

/**
 * binary_tree_uncle -  function
 * @node: pointer
 * Return: pointer
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	return (sibling(node->parent));
}
