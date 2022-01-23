#include "sort.h"

/**
 * merge_swap - Function merge swap
 * @new_array: Pointer new_array value the lengeth
 * @array: Pointers array
 * @middle: Middle of Array
 * @left: Initialition of array
 * @right: integer data of finally
 */

void merge_swap(int *new_array, int *array,
size_t middle, size_t left, size_t right)
{
	size_t i, j, index = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; index++)
		new_array[index] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < middle; i++)
		new_array[index++] = array[i];
	for (; j < right; j++)
		new_array[index++] = array[j];
	for (i = left, index = 0; i < right; i++)
		array[i] = new_array[index++];

	printf("[Done]: ");
	print_array(array + left, right - left);

}

/**
 * merge_recursion - Function merge swap
 * @new_array: Pointer new_array value the lengeth
 * @array: Pointers array
 * @left: Initialition of array
 * @right: Integer data of finally
 */

void merge_recursion(int *new_array, int *array, size_t left, size_t right)
{
	size_t middle = (left + right) / 2;

	if ((right - left) < 2)
		return;
	merge_recursion(new_array, array, left, middle);
	merge_recursion(new_array, array, middle, right);
	merge_swap(new_array, array, middle, left, right);
}

/**
 * merge_sort - Function merge swap
 * @array: Pointers array
 * @size: Size value the lengeth
 */

void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (!array || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return;

	merge_recursion(new_array, array, 0, size);
	free(new_array);
}
