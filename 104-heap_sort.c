#include "sort.h"
/**
* stupify - Function that recurrssive heapSort
* @array: Array integer
* @heap: heap data size
* @x: index
* @size: size of array
*/
void stupify(int *array, int heap, int x, int size)
{
	int lar = x, left = 2 * x + 1, right = 2 * x + 2, y;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != x)
	{
		y = array[x], array[x] = array[lar], array[lar] = y;
		print_array(array, size);
		stupify(array, heap, lar, size);
	}
}
/**
* heap_sort - function  that sorts array with heap sort algo
* @array: array to sort
* @size: Size of array to sort
*/
void heap_sort(int *array, size_t size)
{
	int x = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; x >= 0; x--)
		stupify(array, size, x, size);
	for (x = size - 1; x >= 0; x--)
	{
		temp = array[0];
		array[0] = array[x];
		array[x] = temp;
		if (x > 0)
			print_array(array, size);
		stupify(array, x, 0, size);
	}
}
