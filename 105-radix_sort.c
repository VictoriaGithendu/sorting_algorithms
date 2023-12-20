#include "sort.h"
/**
 * get_max - Function that gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: array size.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	return (max);
}
/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: array size.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < size; x++)
		count[(array[x] / sig) % 10] += 1;
	for (x = 0; x < 10; x++)
		count[x] += count[x - 1];
	for (x = size - 1; (int)x >= 0; x--)
	{
		buff[count[(array[x] / sig) % 10] - 1] = array[x];
		count[(array[x] / sig) % 10] -= 1;
	}
	for (x = 0; x < size; x++)
		array[x] = buff[x];
}
/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: array size.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}
	free(buff);
}
