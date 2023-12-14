#include "sort.h"

/**
 * sort - Sorts two adjacent nodes in the linked
 * list if they are out of order
 * @wnode: Pointer to the node that needs
 *  to be checked for sorting
 * @list: Double pointer to the head of the linked list
 */
void sort(listint_t *wnode, listint_t **list)
{
	listint_t *min = wnode->next, *nodeprev, *minnext, *node;

	while (min->prev != NULL && min->prev->n > min->n)
	{
		node = min->prev;
		nodeprev = node->prev;
		minnext = min->next;
		if (nodeprev != NULL)
			nodeprev->next = min;
		else
			*list = min;

		node->prev = min;
		node->next = minnext;

		min->prev = nodeprev;
		min->next = node;
		if (minnext != NULL)
			minnext->prev = node;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - Sorts a linked
 * list using the insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	int flag = 0;

	node = *list;
	while (node)
	{
		if (node->next != NULL && node->n > node->next->n)
		{
			flag = 1;
			sort(node, list);
		}
		if (!flag)
			node = node->next;
		flag = 0;
	}
}
