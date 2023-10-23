#include "sort.h"

/**
  * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion sort algorithm
  * @list: Pointer to the list being sorted
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *curr = *list, *temp = NULL;
	listint_t *curr_sorted = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		temp = curr->next;
		if (sorted == NULL || sorted->n >= curr->n)
		{
			curr->next = sorted;
			curr->prev = NULL;
			/**
			  * if (sorted != NULL)
			  *	sorted->prev = curr
			  */
			sorted = curr; 
			print_list(*list);
		}
		else
		{
			curr_sorted = sorted;
			while (curr_sorted->next != NULL && curr_sorted->next->n < curr->n)
			{
				curr_sorted = curr_sorted->next;
			}
			curr->next = curr_sorted->next;
			if (curr_sorted->next != NULL)
				curr_sorted->next->prev = curr;

			curr_sorted->next = curr;
			curr->prev = curr_sorted;
			print_list(*list);
		}
		/**
		  * if (curr->prev == NULL)
		  *	*list = curr;
		  */

		curr = temp;
	}

	*list = sorted;

}
