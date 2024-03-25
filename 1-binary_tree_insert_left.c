#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts node as left-child of
 of another in a binary tree.
 * @parent: Pointer to the inserting node.
 * @value: Stored value.
 *
 * Return: Pointer to the new node.
 *
 * Description: In instance where parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_ptr;

	if (parent == NULL)
		return (NULL);

	new_ptr = binary_tree_node(parent, value);
	if (new_ptr == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_ptr->left = parent->left;
		parent->left->parent = new_ptr;
	}
	parent->left = new_ptr;

	return (new_ptr);
}

