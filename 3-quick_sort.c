#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm(Lomuto partition scheme)
 *
 * @array: array to sort
 * @size: array size
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int temp, pivot = array[size - 1], tag = -1;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > pivot)
		{
			tag = i;
		}
		if (array[i] < pivot && tag != -1)
		{
			temp = array[i];
			array[i] = array[tag];
			array[tag] = temp;
			tag = i;
			print_array(array, size);
		}
	}
	quick_sort(array, tag);
	quick_sort(array + tag + 1, size - tag - 1);
}
