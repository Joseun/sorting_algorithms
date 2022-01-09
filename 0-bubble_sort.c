#include "sort.h"
/**
* bubble_sort - Sorts an array of integers in ascending order
* @array: A pointer to the array.
* @size: size of the array.
* Return: nothing.
*/
void bubble_sort(int *array, size_t size)
{
size_t i = 0;
int temp, flag = 0;
while (i != size - 1)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, size);
flag++;
}
i++;
if (i == (size - 1))
{
if (flag == 0)
{
break;
}
else
{
i = 0;
flag = 0;
}
}
}
}
