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
	int fd, n = 0, bool = 1;
	size_t i = 0;
	char *buff;

	if (filename == NULL || letters == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < letters && bool)
	{
		buff = malloc(sizeof(char) * 16);
		if (buff == NULL)
			return (0);
		while (i < letters && n < 16 && bool)
		{
			if (read(fd, &buff[n], 1) > 0)
			{
				i++;
				n++;
			}
			else
			{
				bool = 0;
			}
		}
		if (write(1, buff, n) >= 0)
			n = 0;
		else
			return (0);
		free(buff);
	}
	close(fd);
	return (i);
}
