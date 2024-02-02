#include "binary_trees.h"

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
 * binary_tree_levelorder - function
 * @tree: root
 * @func: function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	fifo_t *head, *tail;
	binary_tree_t *node;

	head = tail = NULL;
	if (tree == NULL || func == NULL)
		return;
	push(&head, &tail, tree);
	while (head)
	{
		node = (binary_tree_t *) pop(&head, &tail);
		if (node)
		{
			push(&head, &tail, (const binary_tree_t *) node->left);
			push(&head, &tail, (const binary_tree_t *) node->right);
			func(node->n);
		}
	}
}
