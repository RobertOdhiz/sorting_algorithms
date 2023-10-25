#include "sort.h"

/**
  * bubble_sort - SOrts an array in ascending order using Bubble Sort
  * @array: Array being sorted
  * @size: Size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int check;

	for (i = 0; i < size - 1; i++)
	{
		check = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				check = 1;
			}
		}

		if (check == 0)
			break;
	}
}

/**
  * swap - Swaps an element with another
  * @first: Reference Element
  * @last: ELement swapped with first
  *
void swap(int *first, int *last)
{
	int temp = *first;

	*first = *last;
	*last = temp;
}/
