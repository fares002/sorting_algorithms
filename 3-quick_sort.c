#include "sort.h"
/**
 * swapping - swapping two node
 * @arr: array
 * @s: size
 * @x: first node
 * @y: second node
 * Return: void
 */
void swapping(int *arr, size_t s, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)arr, s);
	}
}
/**
 * pati - partition
 * @arr: array
 * @size: size of array
 * @low: low nide
 * @high: high node
 * Return: size_t
 */
size_t pati(int *arr, ssize_t size, ssize_t low, ssize_t high)
{
	int a, b, piv = arr[high];

	for (a = b = low; b < high; b++)
		if (arr[b] < piv)
			swapping(arr, size, &arr[b], &arr[a++]);
	swapping(arr, size, &arr[a], &arr[high]);

	return (a);
}
/**
 * q_sort - quick sort
 * @array: array
 * @size: array size
 * @lo: low index
 * @hi: high index
 * Return: void
 */
void q_sort(int *array, size_t size, ssize_t lo, ssize hi)
{
	if (lo < hi)
	{
		size_t p = pati(array, size, lo, hi);

		q_sort(array, size, lo, p - 1);
		q_sort(array, size, p + 1, hi);

}
/**
 * quick_sort - quick sort
 * @array: array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if(!array || !size)
		return;
	q_sort(array, size, 0, size - 1);

