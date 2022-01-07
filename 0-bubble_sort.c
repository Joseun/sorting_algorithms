#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 * @array: A pointer to the array.
 * @size: size of the array.
 *
 * Return: nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int temp;

	for(; i < size - 1; i++)
	{
		if(array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = 0;
		}
		print_array(array, size);
	}
}