#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * swapping - swapping
 * @arr: array
 * @s: size
 * @x: first value
 * @y: second value
 * Return: void
 */
void swapping(int *arr, size_t s, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
	}
	print_array((const int *)arr, s);
}
/**
 * sdown - sift down
 * @arr: array
 * @s: start
 * @e: end
 * @size: size
 * Return: void
 */
void sdown(int *arr, size_t s, size_t e, size_t size)
{
	size_t r = s, _s, child;

	while (leftchild(r) <= e)
	{
		child = leftchild(r);
		_s = r;
		if (arr[_s] < arr[child])
			_s = child;
		if (child + 1 <= e && arr[_s] < arr[child + 1])
			_s = child + 1;
		if (_s == r)
			return;
		swapping(arr, size, &arr[r], &arr[_s]);
		r = _s;
	}
}
/**
 * heapp - heap
 * @array: array
 * @size: size
 * Return: void
 */
void heapp(int *array, size_t size)
{
	ssize_t s;

	s = parent(size - 1);
	while (s >= 0)
	{
		sdown(array, s, size - 1, size);
		s--;
	}
}
/**
 * heap_sort - heap sort
 * @array: array
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t e;

	if (!array || size < 2)
		return;
	heapp(array, size);
	e = size - 1;
	while (e > 0)
	{
		swapping(array, size, &array[e], &array[0]);
		e--;
		sdown(array, 0, e, size);
	}
}
