#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *firstnode, *secondnode;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	firstnode = first->parent, secondnode = second->parent;
	if (first == secondnode || !firstnode || (!firstnode->parent && secondnode))
		return (binary_trees_ancestor(first, secondnode));
	else if (firstnode == second || !secondnode || (!secondnode->parent && firstnode))
		return (binary_trees_ancestor(firstnode, second));
	return (binary_trees_ancestor(firstnode, secondnode));
}
