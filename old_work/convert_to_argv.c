#include "main.h"

void convert_to_argv(char *cmd, char *argv[])
{
	/* split string into argv */
	char *ptr;
	unsigned int i = 0;

	ptr = strtok(cmd, " ");
	while (ptr != NULL)
	{
		/* printf("%s\n", ptr); */
		argv[i] = ptr;
		i++;
		ptr = strtok(NULL, " ");
	}

	/* check for "&" */
	if (!strcmp("&", argv[i - 1]))
	{
		argv[i - 1] = NULL;
		argv[i] = "&";
	}
	else
	{
		argv[i] = NULL;
	}
}
