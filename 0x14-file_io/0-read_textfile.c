#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"

/**
 * read_textfile - Entry point
 * Description: read a text file and print to standard output
 * @filename: pointer to the file
 * @letters: number of letters will be read
 * Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	size_t i = 0;
	char buff[1];

	if (filename == NULL || letters == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buff, 1) > 0 && i < letters)
	{
		if (write(1, buff, 1))
			i++;
		else
			return (0);
	}
	close(fd);
	return (i);
}
