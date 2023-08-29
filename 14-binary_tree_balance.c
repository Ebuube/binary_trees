#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 *
 * Description: if tree is NULL, return 0
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_height = 0, left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/* Ensure this is not leaf node */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	/* USING POST-ORDER TRAVERSAL */
	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	max_height = (left_height > right_height) ? left_height : right_height;

	return (max_height);
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Description: if tree is NULL, return 0
 * Balance factor is the height of the left-subtree (if any) minus
 * the height of the right subtree
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (tree->left != NULL)
		left_height++;
	if (tree->right != NULL)
		right_height++;

	return (left_height - right_height);
}
