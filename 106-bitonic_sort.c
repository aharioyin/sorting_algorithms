#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Func to swap 2 ints in array.
 * @a: head integer to swap.
 * @b: sec integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside array of ints.
 * @array: array of ints.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, skip = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + skip; i++)
		{
			if ((flow == UP && array[i] > array[i + skip]) ||
			    (flow == DOWN && array[i] < array[i + skip]))
				swap_ints(array + i, array + i + skip);
		}
		bitonic_merge(array, size, start, skip, flow);
		bitonic_merge(array, size, start + skip, skip, flow);
	}
}

/**
 * bitonic_seq - Convert array of ints into a bitonic sequence.
 * @array: array of ints.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t slice = seq / 2;
	char *st = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, st);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, slice, UP);
		bitonic_seq(array, size, start + slice, slice, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, st);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort array of ints in ascending
 * order using the bitonic sort algorithm.
 * @array: array of ints.
 * @size: The size of the array.
 *
 * Description: Prints array swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
