#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Function to get max val in array
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: max int in arr.
 */
int get_max(int *array, int size)
{
	int maxim, i;

	for (maxim = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxim)
			maxim = array[i];
	}

	return (maxim);
}

/**
 * radix_counting_sort - Func to Sort sig dig of array
 * in ascending order using counting sort algorithm.
 * @array: An array of integers.
 * @size: size of array.
 * @sig: sig dig to sort on.
 * @buff: A buffer to store sorted arr.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int ite[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		ite[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		ite[i] += ite[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[ite[(array[i] / sig) % 10] - 1] = array[i];
		ite[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Function to ort array of ints in ascending
 * order using radix sort algorithm.
 * @array: An array of integers.
 * @size: size of array.
 *
 * Description:use LSD radix sort algorithm. Prints
 * array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxim, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	maxim = get_max(array, size);
	for (sig = 1; maxim / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
