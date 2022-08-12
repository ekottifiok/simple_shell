#include "shell.h"

/**
 * _putchar - prints out a character
 * @c: input character
 * Return: int on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints a string
 * @param str
 * @param ...
 */
void _printf(char *str, ...)
{
	int i;
	va_list list;

	va_start(list, str);
	if (str)
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] == '%')
			{
				switch (str[i + 1])
				{
					case 'd':
						_printf("%d", va_arg(list, int));
						continue;
					case 'c':
						_putchar(va_arg(list, int));
						continue;
					case 's':
						str = va_arg(list, char *);
						if (!str)
							str = "(nil)";
						printf("%s", str);
						continue;
					case 'f':
						printf("Floating\n");
						continue;
					default:
						_putchar(str[i]);
						continue;
				}
			}
			printf("%c", str[i]);
		}
	}
	printf("\n");
	va_end(list);
}