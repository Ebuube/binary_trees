#include "binary_trees.h"
#include <stdio.h>	/* test */

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor if any,
 * else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;
	list_ancestors_t *ancestors_list = NULL;

	if (first == NULL || first->parent == NULL ||
		second == NULL || second->parent == NULL)
	{/* nodes without parents can't have an ancestor */
		return (NULL);
	}

	ancestors_list = create_list_ancestors((binary_tree_t *)first);
	if (ancestors_list == NULL)
	{/* Can't create parent's list */
		return (NULL);
	}
	ancestor = find_ancestor((binary_tree_t *)second, ancestors_list);

	free_ancestors_list(&ancestors_list);	/* free memory */

	return (ancestor);
}

/**
 * find_ancestor - find a node's ancestor in an ancestor list
 * @node: node to find ancestor
 * @head: a list of ancestors
 *
 * Return: the matching ancestor if any else NULL
 */
binary_tree_t *find_ancestor(binary_tree_t *node, list_ancestors_t *head)
{
	binary_tree_t *ancestor = NULL;
	list_ancestors_t *tmp = NULL;

	if (head == NULL || node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	while (node != NULL)
	{
		tmp = head;
		while (tmp != NULL)
		{
			if (tmp->p == node->parent)
			{
				ancestor = tmp->p;
				break;
			}
			tmp = tmp->next;
		}

		if (ancestor != NULL)
		{/* found an ancestor */
			break;
		}
		node = node->parent;
	}

	return (ancestor);
}

/**
 * create_list_ancestors - creat a list of ancestors of a node
 * @node: to work on
 *
 * Description: current node is included in the ancestor list
 *
 * Return: a pointer to the list else NULL
 */
list_ancestors_t *create_list_ancestors(binary_tree_t *node)
{
	list_ancestors_t *head = NULL, *tail = NULL, *tmp = NULL;

	if (node == NULL)
	{
		return (NULL);
	}

	/* first node in list */
	tmp = malloc(sizeof(list_ancestors_t));
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp->p = node;
	tmp->next = NULL;
	head = tmp;

	for (tail = tmp; node != NULL;)
	{/* make list of ancestors - add node to end of list */
		tmp = malloc(sizeof(list_ancestors_t));
		if (tmp == NULL)
			return (NULL);
		tmp->p = node->parent;
		tmp->next = NULL;
		tail->next = tmp;
		tail = tmp;
		node = node->parent;
	}

	return (head);
}


/**
 * free_ancestors_list - safely free a list of ancestors
 * @head: address of the pointer to the head of the list
 *
 * Return: nothing
 */
void free_ancestors_list(list_ancestors_t **head)
{
	list_ancestors_t *tmp = NULL;

	if (head == NULL || (*head) == NULL)
	{
		return;
	}

	tmp = (*head)->next;
	while ((*head) != NULL)
	{
		free((*head));
		(*head) = tmp;

		if (tmp != NULL)
			tmp = tmp->next;
	}

	(*head) = NULL;	/* safety precaution */
}
