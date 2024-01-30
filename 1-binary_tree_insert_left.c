#include "binary_trees.h"

/**
* binary_tree_insert_left - function to inserts node
* @parent: pointer to the node
* @value: value
* Return: pointer
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode;

	if (parent == NULL)
		return (NULL);

	nwnode = binary_tree_node(parent, value);

	if (nwnode == NULL)
		return (NULL);

	nwnode->left = parent->left;
	if (parent->left != NULL)
		parent->left->parent = nwnode;
	parent->left = nwnode;
	return (nwnode);
}
