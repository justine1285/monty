#include "monty.h"
#include <ctype.h>

/**
 * _isdigit - checks if string is a number
 * @str: (char *) string
 * Return: 1 if string is a number, otherwise -1
 */
int _isdigit(char *str)
{
	int k = 0;

	while (str[k])
	{
		if (!(isdigit(str[k])))
			return (-1);
		k++;
	}
	return (1);
}
