#include "binary_trees.h"

/**
* binary_tree_insert_right - function to insert
* @parent: pointer
* @value: value
* Return: pointer
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode;

	if (parent == NULL)
		return (NULL);
	nwnode = binary_tree_node(parent, value);

	if (nwnode == NULL)
		return (NULL);

	nwnode->right = parent->right;
	if (parent->right != NULL)
		parent->right->parent = nwnode;
	parent->right = nwnode;
	return (nwnode);
}
