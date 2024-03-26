#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: Pointer otherwise NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_ptr;

	if (parent == NULL)
		return (NULL);

	new_ptr = binary_tree_node(parent, value);
	if (new_ptr == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_ptr->right = parent->right;
		parent->right->parent = new_ptr;
	}
	parent->right = new_ptr;

	return (new_ptr);
}

