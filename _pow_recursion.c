#include "shell.h"

/**
 * _pow_recursion - finds the power of number using recursion
 * @x: the base value example 10
 * @y: the power example 2
 * Return: returns the value of 10**2 which is 100
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
