#include "binary_trees.h"

/**
 * binary_tree_delete - delete an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 *
 * Description: if 'tree' is NULL, do nothing
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	/* USING POST-ORDER TRAVERSAL */
	/* VISIT LEFT AND RIGHT NODES THEN THE ROOT NODE */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
