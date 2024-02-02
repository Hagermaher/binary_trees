#include "binary_trees.h"

/**
 * array_to_bst - function
 * @array: array
 * @size: number
 * Return: pointer
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	while (size--)
		bst_insert(&root, *array++);
	return (root);
}
