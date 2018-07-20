#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * rev_string - Entry point
 * Description: reverse a string.
 * @s: string need to be reversed
 *
 * Return: nothing.
 */
void rev_string(char *s)
{
	int i = 0, j;
	int length = 0;
	int temp;

	while (*(s + length) != '\0')
		length++;
	j = length - 1;
	while (i < length / 2)
	{
		temp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = temp;
		i++;
		j--;
	}
	*(s + length) = '\0';
}

/**
 * add2char - Entry point
 * Description: take sum of 2 number characters.
 * @ret: return the value.
 * @m:  keep memory of overflow.
 * @n1: first char.
 * @n2: second char.
 *
 * Return: nothing.
 */
void add2char(char *ret, char *m, char n1, char n2)
{
	int num = 0;

	num = n1 - '0' + n2 - '0';
	*ret = num % 10 + '0';
	*m = num / 10 + '0';
}
/**
 * mul2char - Entry point
 * Description: multiple 2 number character.
 * @ret: return the value.
 * @m:  keep memory of overflow.
 * @n1: first char.
 * @n2: second char.
 *
 * Return: nothing.
 */
void mul2char(char *ret, char *m, char n1, char n2)
{
	int num = 0;

	num = (n1 - '0') * (n2 - '0');
	*ret = num % 10 + '0';
	*m = num / 10 + '0';
}

/**
 * _memcpy - Entry point
 * Description: fills the first n bytes of the memory area.
 * @dest: string that need to filled by source.
 * @src:  bytes form source will be pasted to dest.
 * @n: n of bytes to be filled.
 *
 * Return: pointer to the memory area s.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _realloc - Entry point
 * Description: re allocate memory
 * @ptr: pointer point to old memory space.
 * @old_size: old size
 * @new_size: new size
 *
 * Return: new pointer to new size of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *re_ptr = NULL;

	if (old_size == new_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		re_ptr = malloc(new_size);
		if (re_ptr == NULL)
			return (NULL);
		return (re_ptr);
	}
	else
	{
		re_ptr = malloc(new_size);
		if (re_ptr == NULL)
			return (NULL);
		if (new_size > old_size)
		{
			_memcpy(re_ptr, ptr, old_size);
		}
		else
		{
			_memcpy(re_ptr, ptr, new_size);
		}
	}
	free(ptr);
	return (re_ptr);
}
/**
 * main - Entry point
 * Description: multiple of 2 string of numbers
 * @argc: number of argument
 * @argv: pointer to pointer to string of numbers
 *
 * Return: string of result after multiply.
 */
int main(int argc, char **argv)
{
	char *n1;
	char *n2;
	char *result, *temp_re;
	char ret = '0', m1 = '0', m2 = '0';
	unsigned int l1, l2, l;
	unsigned int i, j, k, m;

	if (argc != 3)
		exit(98);
	for (i = 0, l1 = 0; argv[1][i] != '\0'; i++, l1++)
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(98);
	for (i = 0, l2 = 0; argv[2][i] != '\0'; i++, l2++)
		if (argv[2][i] < '0' || argv[2][i] > '9')
			exit(98);
	l = l1 + l2;
	n1 = malloc(sizeof(char) * l1 + 1);
	if (n1 == NULL)
		exit(98);
	n2 = malloc(sizeof(char) * l2 + 1);
	if (n2 == NULL)
		exit(98);
	temp_re = malloc(sizeof(char) * l2 + 1);
	if (temp_re == NULL)
		exit(98);
	result = malloc(sizeof(char) * l);
	if (result == NULL)
		exit(98);
	for (i = 0; i <= l; i++)
	{
		result[i] = '0';
	}
	rev_string(argv[1]);
	_memcpy(n1, argv[1], l1);
	rev_string(argv[2]);
	_memcpy(n2, argv[2], l2);
	for (i = 0; i < l1; i++)
	{
		ret = '0';
		m1 = '0';
		m2 = '0';
		temp_re = _realloc(temp_re, (l2 + i - 1 + 1), (l2 + i + 1));
		if (temp_re == NULL)
			exit(98);
		for (j = 0, k = 0; j < l2; j++, k++)
		{
			mul2char(&ret, &m2, n1[i], n2[j]);
			add2char(&ret, &m1, ret, m1);
			m1 = m2;
			while (k < i)
			{
				temp_re[k] = '0';
				k++;
			}
			temp_re[k] = ret;
		}
		temp_re[k++] = m1;
		temp_re[k] = '\0';
		for (m = 0; m < k; m++)
		{
			add2char(&ret, &m2, result[m], temp_re[m]);
			add2char(&ret, &m1, ret, m1);
			m1 = m2;
			result[m] = ret;
		}
		if (m2 != '0')
			result[m] = m2;
	}
	while (result[m] == '0')
	{
		result[m] = '\0';
		m--;
	}
	rev_string(result);
	printf("result is %s\n", result);
	free(n1);
	free(n2);
	free(temp_re);
	free(result);
	return (0);
}
