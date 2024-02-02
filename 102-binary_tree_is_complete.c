#include "binary_trees.h"

/**
 * binary_tree_leaves - function
 * @tree: pointer
 * Return: tree is NULL, the function must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}

/**
 * push - function
 * @head: pointer
 * @tail: pointer
 * @node: node
 */
void push(fifo_t **head, fifo_t **tail, const binary_tree_t *node)
{
	fifo_t *new;

	if (head == NULL || node == NULL)
		return;
	new = malloc(sizeof(fifo_t));
	if (new == NULL)
		return;
	new->node = node;
	new->next = *head;
	new->prev = NULL;
	if (*head == NULL)
		*tail = new;
	else
		(*head)->prev = new;
	*head = new;
}

/**
 * pop - function
 * @head: pointer
 * @tail: pointer
 * Return: pointer
 */
const binary_tree_t *pop(fifo_t **head, fifo_t **tail)
{
	fifo_t *last;
	binary_tree_t *node;

	if (tail == NULL || *tail == NULL)
		return (NULL);
	last = *tail;
	*tail = (*tail)->prev;
	if (*tail == NULL)
		*head = NULL;
	else
		(*tail)->next = NULL;
	node = (binary_tree_t *) last->node;
	free(last);
	return ((const binary_tree_t *) node);
}

/**
 * binary_tree_is_complete - function
 * @tree: pointer
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	fifo_t *head, *tail;
	binary_tree_t *node;

	head = tail = NULL;
	if (tree == NULL)
		return (0);
	push(&head, &tail, tree);
	while (head)
	{
		node = (binary_tree_t *) pop(&head, &tail);
		if (node)
		{
			push(&head, &tail, (const binary_tree_t *) node->left);
			push(&head, &tail, (const binary_tree_t *) node->right);
			if (binary_tree_leaves(node))
			{
				if (node->parent->left == NULL)
					return (0);
			}
		}
	}
	return (1);
}
