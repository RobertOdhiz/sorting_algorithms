#include "sort.h"

/**
  * insertion_sort_list - Sorts a doubly linked list of integers in ascending
  * order using Insertion sort algorithm
  *
  * @list: Pointer to the list being sorted
  * Return: Nothing
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	while (temp->next)
	{
		if (temp->next->n < temp->n)
		{
			curr = temp;
			temp = temp->next;
			/*swap */
			temp->prev = curr->prev;
			if (curr->prev)
				curr->prev->next = temp;
			else
				*list = temp;
			curr->next = temp->next;
			if (temp->next)
				temp->next->prev = curr;
			temp->next = curr;
			curr->prev = temp;
			print_list(*list); /*print list*/
			if (temp->prev && temp->n < temp->prev->n)
				temp = temp->prev;
			else
				temp = temp->next;

		}
		else
			temp = temp->next;
	}
}
