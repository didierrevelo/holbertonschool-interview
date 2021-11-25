#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @array: The array to be sorted
 * @i: The first element
 * @j: The second element
 * Return: void
 */
void swap(int *array, size_t i, size_t j)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, 10);
	}
}
/**
 * sift_down - Sifts down an element in an array
 * @array: The array to be sorted
 * @size: The size of the array
 * @index: The root of the heap
 * Return: void
 */
void sift_down(int *array, size_t size, size_t index)
{
	size_t left, right, largest;

	left = 2 * index + 1;
	right = 2 * index + 2;
	largest = index;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(array, index, largest);
		sift_down(array, size, largest);
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
	size_t i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i > 0; i--)
		sift_down(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		sift_down(array, i, 0);
	}
}
