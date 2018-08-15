#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"

/**
 * main - Entry point
 * Description: copy from file to file
 * @argc: number of arguments
 * @argv: pointer to pointer to argument
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd1, fd2, i, n = 0;
	char *buff;
	char rd[] = "Error: Can\'t read from file";
	char wr[] = "Error: Can\'t write to";
	char cl[] = "Error: Can\'t close fd";

	if (argc != 3)
	{
		dprintf(STDOUT_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDOUT_FILENO, "%s %s\n", rd, argv[1]);
		exit(98);
	}
	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd2 == -1)
	{
		dprintf(STDOUT_FILENO, "%s %s\n", wr, argv[2]);
		exit(99);
	}
	while (1)
	{
		buff = malloc(sizeof(char) * 1024);
		if (buff == NULL)
			return (0);
		n = read(fd1, buff, 1024);
		if (n > 0)
		{
			if (write(fd2, buff, n) >= 0)
				;
			else
			{
				dprintf(STDOUT_FILENO, "%s %s\n", wr, argv[2]);
				exit(99);
			}
		}
		else if (n < 0)
		{
			dprintf(STDOUT_FILENO, "%s %s\n", rd, argv[1]);
			exit(98);
		}
		else
			break;
		free(buff);
	}
	i = close(fd1);
	if (i < 0)
	{
		dprintf(STDOUT_FILENO, "%s %i\n", cl, fd1);
		exit(100);
	}
	i = close(fd2);
	if (i < 0)
	{
		dprintf(STDOUT_FILENO, "%s %i\n", cl, fd2);
		exit(100);
	}
	return (0);
}
