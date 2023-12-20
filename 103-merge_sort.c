#include "sort.h"
#include<stdio.h>
/**
 * merge -  Function that sorts array using merge sort
 * @array: array
 * @size: size of the array
 * @l: pointer to left array
 * @r: pointer to right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int x = 0, y = 0, z = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_left);
	printf("[right]: ");
	print_array(r, size_right);
	while (x < size_left && y < size_right)
	{
		if (l[x] < r[y])
			array[z++] = l[x++];
		else
			array[z++] = r[y++];
	}
	while (x < size_left)
		array[z++] = l[x++];

	while (y < size_right)
		array[z++] = r[y++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - Fuction that sorts an array of integers in ascending order
 * @array: array pointer
 * @size: array size
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, x;
	int left[1000];
	int right[1000];

	if (!array)
		return;
	if (size < 2)
		return;
	mid = size / 2;
	for (x = 0; x < mid; x++)
		left[x] = array[x];
	for (x = mid; x < size; x++)
		right[x - mid] = array[x];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
