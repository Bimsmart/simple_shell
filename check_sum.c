#include <stdio.h>
#include "main.h"
/**
 * check_sum - this function calculates the sum of two numbers
 * @x: first integer
 * @y: second integer
 * Return: 0;
 */
int check_sum(int x, int y)
{
	return (x + y);
}
/**
 * main - the main entry
 *
 * Return: 0
 */
int main(void)
{
	int a = 4;
	int b = 3;

	printf("THe sum of the two numbers is: %d\n", check_sum(a, b));
	return (0);
}
