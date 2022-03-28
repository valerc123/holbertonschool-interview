#include "regex.h"

/**
 * regex_match - Check whenever a string matches with a given pattern.
 * @str: String to check
 * @pattern: The regular expression
 * Return: 1 if the pattern matches the string, 0 if otherwise.
 */

int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0' && (*pattern == '*' || *pattern == '\0'))
			return (1);
		return (0);
	}
	if (*pattern == '*')
	{
		if (*str == *(pattern + 1) || *(pattern + 1) == '.')
			return (regex_match(str, pattern + 1));
		if (*str == *(pattern - 1) || *(pattern - 1) == '.')
			return (regex_match(str + 1, pattern));
	}
	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 1));
	if (*pattern == '.' || *str == *pattern)
		return (regex_match(str + 1, pattern + 1));
	return (0);
}