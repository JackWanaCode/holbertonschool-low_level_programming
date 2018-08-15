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
	char error_str[] = "Error: Can\'t read from file";

	if (argc != 3)
	{
		write(STDOUT_FILENO, "Usage: cp file_from file_to\n", 28);
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		write(STDOUT_FILENO, error_str, 27);
		dprintf(STDOUT_FILENO, " %s\n", argv[1]);
		exit(98);
	}
	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd2 == -1)
	{
		write(STDOUT_FILENO, error_str, 27);
		dprintf(STDOUT_FILENO, " %s\n", argv[2]);
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
				continue;
			else
			{
				write(STDOUT_FILENO, error_str, 27);
				dprintf(STDOUT_FILENO, " %s\n", argv[2]);
				exit(99);
			}
		}
		else if (n < 0)
		{
			write(STDOUT_FILENO, error_str, 27);
			dprintf(STDOUT_FILENO, " %s\n", argv[1]);
			exit(98);
		}
		else
			break;
		free(buff);
	}
	i = close(fd1);
	if (i < 0)
	{
		write(STDOUT_FILENO, "Error: Can\'t close fd FD_VALUE\n", 31);
		exit(100);
	}
	i = close(fd2);
	if (i < 0)
	{
		write(STDOUT_FILENO, "Error: Can\'t close fd FD_VALUE\n", 31);
		;
		exit(100);
	}
	return (0);
}
