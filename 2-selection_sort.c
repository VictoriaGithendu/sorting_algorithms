#include "sort.h"
/**
 * selection_sort - function that sorts an array
 *@size:  size of array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t x, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (x = 0; x < size; x++)
	{
		tmp = x;
		flag = 0;
		for (index = x + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[x];
		array[x] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
