#include "binary_trees.h"

/**
 * binary_tree_node - code generates a binary tree node.
 * @parent: first parameter
 * @value: second parameter
 *
 * Return: Pointer
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_ptr;

	new_ptr = malloc(sizeof(binary_tree_t));
	if (new_ptr == NULL)
		return (NULL);

	new_ptr->n = value;
	new_ptr->parent = parent;
	new_ptr->left = NULL;
	new_ptr->right = NULL;

	return (new_ptr);
}

