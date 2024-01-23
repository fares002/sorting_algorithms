#include "sort.h"

/**
 * m_compare - marge compare
 * @arr: array
 * @s: start
 * @st: stop
 * @n: new
 * Return: void
 */
void m_compare(int *arr, size_t s, size_t st, int *n)
{
	size_t i = s, j, k, m;

	j = m = (s + st) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + s, m - s);
	printf("[right]: ");
	print_array(arr + m, st - m);
	for (k = s; k < st; k++)
		if (i < m && (j >= st || arr[i] <= arr[j]))
		{
			n[k] = arr[i++];
		}
		else
			n[k] = arr[j++];
	printf("[Done]: ");
	print_array(n + s, st - s);
}
/**
 * m_sort - sorts top down
 * @arr: array
 * @s: start
 * @st: stop
 * @n: new
 * Return: void
 */
void m_sort(int *arr, size_t s, size_t st, int *n)
{
	size_t m;

	m = (s + st) / 2;
	if (st - s < 2)
		return;
	m_sort(n, s, m, arr);
	m_sort(n, m, st, arr);
	m_compare(arr, s, st, n);
}
/**
 * merge_sort - merge sort
 * @array: array
 * @size: size of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *n;
	size_t j;

	if (!array || size < 2)
		return;

	n = malloc(sizeof(int) * size);
	if (!n)
		return;
	for (j = 0; j < size; j++)
		n[j] = array[j];
	m_sort(n, 0, size, array);
	free(n);
}
