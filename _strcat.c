#include "shell.h"

/**
 * _strcat - works like the famous strcat
 * @dest: resulting string
 * @src: source string
 * Return: the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int size_dest, iter;

	size_dest = _strlen(dest);
	for (iter = size_dest; src[iter - size_dest] != '\0'; iter++)
		dest[iter] = src[iter - size_dest];
	dest[iter] = '\0';
	return (dest);
}
