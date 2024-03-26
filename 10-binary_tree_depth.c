#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node.
 * @tree: A pointer to the node to measuring depth.
 *
 * Return: depth otherwise 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

