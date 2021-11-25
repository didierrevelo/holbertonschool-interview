#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @array: The array to be sorted
 * @i: The first element
 * @j: The second element
 * @r_size: The size of the array
 * Return: void
 */
void swap(int *array, int i, int j, const int r_size)
{
	int tmp;
	(void)r_size;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * sift_down - Sifts down an element in an array
 * @array: The array to be sorted
 * @i: The element to be sifted down
 * @size: The size of the array
 * @r_size: The root of the heap
 * Return: void
 */
void sift_down(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != i)
	{
		swap(array, i, largest, r_size);
		sift_down(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap
 * sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i, r_size);
		sift_down(array, i, 0, r_size);
	}
}
