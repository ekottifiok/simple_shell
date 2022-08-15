#include "shell.h"

/**
 * file_descriptor_no - converts the stream input to size_t
 * @stream: input stream
 * Return: -1 failure and above greater than -1 success
 */
int file_descriptor_no(FILE *stream)
{
	if (stream == stdin)
		return (STDIN_FILENO);
	else if (stream == stdout)
		return (STDOUT_FILENO);
	else if (stream == stderr)
		return (STDERR_FILENO);
	else
		return (-1);
}

/**
 * _getline - simple implementation of the getline
 * @line_ptr: pointer to the string location
 * @n: size of data to be read
 * @stream: either stdin or stdout
 * Return:  size of data actually read
 */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	char *read_line;
	ssize_t size_line;

	read_line = malloc(sizeof(char) * *n);
	size_line = read(file_descriptor_no(stream), read_line, *n);
	if (size_line == -1)
		return (-1);
	if (*line_ptr)
		free(*line_ptr);
	*line_ptr = read_line;
	return (size_line);
}
