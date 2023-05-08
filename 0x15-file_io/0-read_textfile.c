#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads and prints from a file
 * @filename: path to the file
 * @letters: number of characters to read
 *
 * Return: number of characters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *buffer;
	ssize_t bytes_read, bytes_written, result;

	if (!filename)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		close(file_descriptor);
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(file_descriptor);
		return (0);
	}
	bytes_read = read(file_descriptor, buffer, letters);

	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (bytes_written == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	close(file_descriptor);
	free(buffer);
	result = bytes_written;
	return (result);
}

