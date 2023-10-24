#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: integer array
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t j, pin, i = 0;
	int min = 0;

	if (size == 1)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				pin = j;
			}

		}
		if (min < array[i])
		{
			array[pin] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
