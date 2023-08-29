#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a given node is a root
 * @node: pointer to node to check
 *
 * Description: If node is NULL, return 0
 *
 * Return: 1 if node is root, otherwise, 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int ret = 0;

	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{/* A root node has no parent */
		ret = 1;
	}

	return (ret);
}
