#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

int copy_file(const char *source_file, const char *destination_file);
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (copy_file(argv[1], argv[2]) == -1)
	{
		exit(99);
	}

	return (0);
}
/**
 * copy_file - Copies the contents of one file to another.
 * @source_file: The path of the source file.
 * @destination_file: The path of the destination file.
 * Return: 0 on success, -1 on failure.
 */

int copy_file(const char *source_file, const char *destination_file)
{
	int source_fd, destination_fd, r, w;
	char buffer[1024];

	source_fd = open(source_file, O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, source_file);
		return (-1);
	}

	destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (destination_fd == -1)
	{
		dprintf(STDERR_FILENO, WRITE_ERR, destination_file);
		close(source_fd);
		return (-1);
	}

	while ((r = read(source_fd, buffer, 1024)) > 0)
	{
		w = write(destination_fd, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, WRITE_ERR, destination_file);
			close(source_fd);
			close(destination_fd);
			return (-1);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, source_file);
		close(source_fd);
		close(destination_fd);
		return (-1);
	}

	if (close(source_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		return (-1);
	}

	if (close(destination_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destination_fd);
		return (-1);
	}

	return (0);
}

