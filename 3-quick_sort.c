#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm(Lomuto partition scheme)
 *
 * @array: array to sort
 * @size: array size
 * Return: Notubng
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);	
}

/**
  * partition - Partitions the array into sub arrays
  * @array: Array being partitioned
  * @lb: Lowerbound of the array
  * @ub: Upperbound of the array
  * @size: Size of the array
  * Return: An integer that stores the point of partition
  */

int partition(int *array, int lb, int ub, size_t size)
{
	int i = lb - 1, j = lb;
	int pivot = array[ub];

	for (; j < ub; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[ub])
	{
		swap(&array[i + 1], &array[ub]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_s - quick sort
 * @array: given array
 * @lb: lbwer
 * @ub:ubgher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lb, int ub, size_t size)
{
	int pivot;

	if (lb < ub)
	{
		pivot = partition(array, lb, ub, size);
		quick_s(array, lb, pivot - 1, size);
		quick_s(array, pivot + 1, ub, size);
	}
}
