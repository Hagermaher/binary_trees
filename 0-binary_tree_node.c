#include "binary_trees.h"
/**
* binary_tree_node - function to create binary tree
* @parent: node
* @value: value
* Return: pointer
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode = malloc(sizeof(binary_tree_t));

	if (nwnode == NULL)
		return (NULL);

	nwnode->n = value;
	nwnode->parent = parent;
	nwnode->left = NULL;
	nwnode->right = NULL;
	return (nwnode);
}
