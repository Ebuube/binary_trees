#include "binary_trees.h"

/**
 * tree_is_perfect - check if a binary tree is a perfect tree
 * @tree: a pointer to the root of the tree
 * @level: the level at which this is, in the master tree
 * @height: height of the master tree
 *
 * Return: 1 if tree is perfect, else 0
 */
int tree_is_perfect(const binary_tree_t *tree, int level, const int height)
{
	int ret = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/* LEAF NODE */
	if (tree->left == NULL && tree->right == NULL)
	{
		ret = (level == height) ? 1 : 0;
		return (ret);
	}

	if (tree_is_perfect(tree->left, level + 1, height) &&
		tree_is_perfect(tree->right, level + 1, height))
	{
		ret = 1;
	}
	else
		ret = 0;

	return (ret);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 *
 * Description: In a perfect tree, all nodes except the leaf nodes have
 * exactly two child nodes and all the leaf nodes are at the same level.
 * If tree is NULL, return 0
 *
 * Return: 1 if tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;
	int height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	tmp = (binary_tree_t *)tree;

	/* It doesn't matter whether right or left for a perfect tree */
	while (tmp != NULL && tmp->left != NULL)
	{
		height++;
		tmp = tmp->left;
	}

	/* This is the master root node */
	return (tree_is_perfect(tree, 0, height));
}
