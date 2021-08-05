#include "binary_trees.h"

/**
 * binary_tree_node - creates a node of a binary tree with null children
 * @parent:  is a pointer to the parent node of the node to create
 * @value:  is the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *runner = NULL;

	runner = malloc(sizeof(binary_tree_t));
	if (runner == NULL)
		return (NULL);

	runner->parent = parent;
	runner->left = NULL;
	runner->right = NULL;
	runner->n = value;

	return (runner);
}
