#include <stdio.h>
#include "sort.h"

/**
 * swap - a function that swaps two integers
 * @xp: integer pointer
 * @yp: integer pointer
 * Return: 0
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - a function that sort  arrays of integers
 * @array: integer pointer
 * @size: size of the arrray
 * Return: 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
