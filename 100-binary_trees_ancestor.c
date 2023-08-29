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
	list_ancestors_t *f_ancestors_list = NULL, *s_ancestors_list = NULL;

	if (first == NULL || first->parent == NULL ||
		second == NULL || second->parent == NULL)
	{/* nodes without parents can't have an ancestor */
		return (NULL);
	}

	f_ancestors_list = create_list_ancestors(first);
	s_ancestors_list = create_list_ancestors(second);
	if (f_ancestors_list == NULL || s_ancestors_list == NULL)
	{/* Can't create parent's list */
		return (NULL);
	}
	ancestor = (binary_tree_t *)find_first_match(f_ancestors_list,
			s_ancestors_list);

	free_ancestors_list(&f_ancestors_list);	/* free memory */
	free_ancestors_list(&s_ancestors_list);	/* free memory */

	return (ancestor);
}

/**
 * find_first_match - finds the first mathing ancestors in a list of ancestors
 * @list_1: first list of ancestors
 * @list_2: second list of ancestors
 *
 * Return: the first matching ancestors in the two starting from index 0
 * else NULL if not found
 */
binary_tree_t *find_first_match(const list_ancestors_t *list_1,
	const list_ancestors_t *list_2)
{
	const list_ancestors_t *tmp = NULL;

	if (list_1 == NULL || list_2 == NULL)
	{
		return (NULL);
	}

	for (; list_1 != NULL; list_1 = list_1->next)
	{
		for (tmp = list_2; tmp != NULL; tmp = tmp->next)
		{
			if (list_1->p == tmp->p)
			{
				return ((binary_tree_t *)list_1->p);
			}
		}
	}

	return (NULL);	/* NO MATCH FOUND */
}

/**
 * find_ancestor - find a node's ancestor in an ancestor list
 * @node: node to find ancestor
 * @head: a list of ancestors
 *
 * Return: the matching ancestor if any else NULL
 */
const binary_tree_t *find_ancestor(const binary_tree_t *node,
	list_ancestors_t *head)
{
	const binary_tree_t *ancestor = NULL;
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
list_ancestors_t *create_list_ancestors(const binary_tree_t *node)
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
