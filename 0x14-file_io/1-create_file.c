#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"

/**
 * create_file - Entry point
 * Description: read a text file and print to standard output
 * @filename: pointer to the file
 * @text_content: pointer to a string of content.
 * Return: 1 on success, otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	int i, fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		if (write(fd, text_content, i) >= 0)
			;
		else
			return (-1);
	}
	close(fd);
	return (1);
}
