#include <stdio.h>

/**
 * main - Entry point
 * Description: print 98 fibnum by standard lib. long long, array not allowed
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int f = 0, s = 0, t = 1;
	int firstt = 0, secondt = 1;
	int firsts = 0, seconds = 0;
	int firstf = 0, secondf = 0;
	int rf = 0, rs = 0;
	int count = 0;
	int l = 0;
	int c = 0;

	while (count < 98)
	{
		if (f > 0)
		{
			printf("%i", f);
			l = s;
			while ((l) >= 1)
			{
				l = l / 10;
				c++;
			}
			while ((7 - c) > 0)
			{
				printf("%i", 0);
				c++;
			}
			l = 0;
			c = 0;
		}
		if (s > 0)
		{
			printf("%i", s);
			l = t;
			while (l >= 1)
			{
				l = l / 10;
				c++;
			}
			while ((7 - c) > 0)
			{
				printf("%i", 0);
				c++;
			}
			l = 0;
			c = 0;
		}
		printf("%i", t);
		if (count < 97)
			printf(", ");
		count++;
		firstt = secondt;
		secondt = t;
		t = firstt + secondt;
		firsts = seconds;
		seconds = s;
		if (t >= 10000000)
		{
			t = t - 10000000;
			rs = 1;
		}
		s = rs + firsts + seconds;
		rs = 0;
		firstf = secondf;
		secondf = f;
		if (s >= 10000000)
		{
			s = s - 10000000;
			rf = 1;
		}
		f = rf + firstf + secondf;
		rf = 0;
	}
	putchar('\n');
	return (0);
}
