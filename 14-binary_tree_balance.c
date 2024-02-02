#include "binary_trees.h"
#define max(a, b) ((a) >= (b) ? (a) : (b))

/**
 * _binary_tree_height - function
 * @tree: pointer
 * Return: return 0
 */

size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(_binary_tree_height(tree->left),
				_binary_tree_height(tree->right)));
}
/**
 * binary_tree_balance - function
 * @tree: pointer
 * Return: return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
		if (tree == NULL)
			return (0);
		return (_binary_tree_height(tree->left) -
		_binary_tree_height(tree->right));

}
