#include "palindrome.h"
#define MAX 100

/**
 * num_digit - function returns number of digits of a number
 *
 * @num: number to be checked
 *
 * Return: number of digits
 */
unsigned long num_digit(unsigned long num)
{
	unsigned long count = 0;

	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * reverse - revert a string
 *
 * @str: strign to be reverted
 *
 * Return: string reverted
 */
char *reverse(char *str)
{
	static int i;
	static char revstr[MAX];

	if (*str)
	{
		reverse(str + 1);
		revstr[i++] = *str;
	}
	return (revstr);
}

/**
 * is_palindrome - function that checks
 * whether or not a given unsigned integer is a palindrome
 *
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long digit = num_digit(n);
	char buffer[sizeof(unsigned long) * digit + 1];
	char copy[sizeof(unsigned long) * digit + 1];
	char *revstr;

	sprintf(buffer, "%lu", n);
	strcpy(copy, buffer);
	revstr = reverse(copy);
	if (!strcmp(buffer, revstr))
		return (1);
	else
		return (0);
}
