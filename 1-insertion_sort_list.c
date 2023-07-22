#include "sort.h"

/**
 * swapnode - swaps the node with the previous node
 * @node: the node to be swapped
 * @head: head of the list
 * Return: head of the list
 */

listint_t  *swapnode(listint_t *head, listint_t *node)
{
	listint_t *tempnext = node->next;
	listint_t *tempprev = node->prev;
	listint_t *tempprevprev = node->prev->prev;

	node->next = tempprev;
	node->prev = tempprev->prev;
	tempprev->next = tempnext;
	tempprev->prev = node;
	if (tempprevprev != NULL)
	{
		tempprevprev->next = node;
	}
	else
	{
		head = node;
	}
	if (tempnext)
	{
		tempnext->prev = tempprev;
	}
	return (head);
}

/**
 * insertion_sort_list - sorts the linked list by insertion sort
 * @list: head of the list tobe sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *lis = *list;
	listint_t *head = *list;

	while (lis->next)
	{
		lis = lis->next;
		while (lis->prev != NULL && lis->n < lis->prev->n)
		{
			head = swapnode(head, lis);
			print_list(head);
		}
	}

	*list = head;
}
