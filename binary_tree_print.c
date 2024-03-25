#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original print code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of str
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: pointer buffer
 *
 * Return: length
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, index;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (index = 0; index < width; index++)
		s[depth][offset + left + index] = b[index];
	if (depth && is_left)
	{
		for (index = 0; index < width + right; index++)
			s[depth - 1][offset + left + width / 2 + index] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (index = 0; index < left + width; index++)
			s[depth - 1][offset - width / 2 + index] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Displays the height of a binary tree
 * @tree: Pointer to the node
 * Return: The height of the tree starting at @node
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t h_l;
	size_t h_r;

	h_l = tree->left ? 1 + _height(tree->left) : 0;
	h_r = tree->right ? 1 + _height(tree->right) : 0;
	return (h_l > h_r ? h_l : h_r);
}

/**
 * binary_tree_print - Outputs binary tree
 * @tree: Pointer to the root node of the binary tree
 */

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}

