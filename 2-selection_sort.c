#include "sort.h"

/**
 * swap_ints - funct to swap two ints in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of ints in ascending order
 * using selection sort algorithm.
 * @array: An array of ints.
 * @size: size of array.
 *
 * Description: Prints array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;

		if ((array + i) != minimum)
		{
			swap_ints(array + i, minimum);
			print_array(array, size);
		}
	}
}
