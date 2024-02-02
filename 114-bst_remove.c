#include "binary_trees.h"

/**
 * bst_search - search for value
 * @tree: root
 * @value: value
 * Return: pointer
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *) tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}

/**
 * simple_remove - function
 * @root: root
 * @to_remove: node
 * @parent: pointer
 * Return: pointer
 */
bst_t *simple_remove(bst_t *root, bst_t *to_remove, bst_t **parent)
{
	if (to_remove->parent == NULL)
	{
		free(to_remove);
		return (NULL);
	}
	*parent = NULL;
	free(to_remove);
	return (root);
}

/**
 * left_remove - function
 * @root: root
 * @to_remove: node
 * @parent: pointer
 * Return: pointer
 */
bst_t *left_remove(bst_t *root, bst_t *to_remove, bst_t **parent)
{
	to_remove->left->parent = to_remove->parent;
	if (to_remove->parent == NULL)
	{
		root = to_remove->left;
		free(to_remove);
		return (root);
	}
	*parent = to_remove->left;
	free(to_remove);
	return (root);
}

/**
 * bst_remove - remove node
 * @root: root
 * @value: value
 * Return: pointer
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t **parent, *child, *to_remove = bst_search(root, value);

	if (to_remove == NULL)
		return (root);
	if (to_remove->parent != NULL)
		parent = (to_remove == to_remove->parent->left ?
			  &to_remove->parent->left : &to_remove->parent->right);
	if (to_remove->right == NULL)
	{
		if (to_remove->left == NULL)
			return (simple_remove(root, to_remove, parent));
		else
			return (left_remove(root, to_remove, parent));
	}
	else
	{
		child = to_remove->right;
		while (child->left != NULL)
			child = child->left;
		if (child != to_remove->right)
		{
			to_remove->right->parent = child;
			child->parent->left = child->right;
			if (child->right != NULL)
				child->right->parent = child->parent;
			child->right = to_remove->right;
		}
		if (to_remove->left != NULL)
			to_remove->left->parent = child;
		child->left = to_remove->left;
		child->parent = to_remove->parent;
		if (to_remove->parent == NULL)
		{
			free(to_remove);
			return (child);
		}
		free(to_remove);
		*parent = child;
		return (root);
	}
}
