#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Description: If tree is NULL, return 0
 *
 * Return: the number of nodes satisfying this condition
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0, left_nodes = 0, right_nodes = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL || tree->right != NULL)
	{
		nodes++;
	}

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	nodes += left_nodes + right_nodes;

	return (nodes);
}
