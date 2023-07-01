#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - funct to swap 2 ints array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of array of ints
 * according to hoare partition scheme.
 * @array: array of ints.
 * @size: size of array.
 * @left: starting index of subset to order.
 * @right: ending index of subset to order.
 *
 * Return: final partition index.
 *
 * Description: Uses last element of partition.
 * Prints array after swap.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int point, top, bottom;

	point = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < point);
		do {
			bottom--;
		} while (array[bottom] > point);

		if (top < bottom)
		{
			swap_ints(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - Implement quicksort algorithm through recursion.
 * @array: An array of ints to sort.
 * @size: size of array.
 * @left: starting index of array partition to order.
 * @right: ending index of array partition to order.
 *
 * Description: Uses Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int seq;

	if (right - left > 0)
	{
		seq = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, seq - 1);
		hoare_sort(array, size, seq, right);
	}
}

/**
 * quick_sort_hoare - Sort array of ints in ascending
 * order using quicksort algorithm.
 * @array: array of ints.
 * @size: size of array.
 *
 * Description: Hoare partition scheme. Print
 * array after swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
