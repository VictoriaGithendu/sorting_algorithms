#include "sort.h"
/**
 *bubble_sort - Function that sorts an integer array in ascending order
 *@array: array of numbers
 *@size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int number;

	if (array == NULL  || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				number = array[y];
				array[y] = array[y + 1];
				array[y + 1] = number;
				print_array(array, size);
			}
		}
	}
}
