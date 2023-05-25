#include "main.h"
#define BIFF_SIZE 1024
/**
 * mygetline - custom getline finc
 * @buffer:buffer itself
 * Return:number of char minus newline
 */
ssize_t mygetline(char **ptr, size_t *n, FILE *stream)
{
	static char buff[BIFF_SIZE];
	static ssize_t buffersize = 0;
	static size_t bufferpos = 0;
	ssize_t total = 0;
	ssize_t lsize = 0;
	char *newline = NULL;
	char *newptr;

	
	if (ptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*ptr == NULL || *n == 0)
	{
		*n = BIFF_SIZE;
		*ptr = (char *)malloc(*n);
		if (*ptr == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		if ((ssize_t)bufferpos >= buffersize)
		{
			buffersize = read(fileno(stream), buff, BIFF_SIZE);
			if (buffersize <= 0)
			{
				break;
			}
			bufferpos = 0;
		}

		newline = memchr(buff + bufferpos, '\n', buffersize - bufferpos);
		if (newline != NULL)
		{
			lsize = newline - (buff + bufferpos) + 1;
		}
		else
		{
			lsize = buffersize - bufferpos;
		}
		if ((size_t)(total + lsize) > *n)
		{
			*n *= 2;
			newptr = (char *)realloc(*ptr, *n);
			if (newptr == NULL)
			{
				return (-1);
			}
			*ptr = newptr;
		}
	
		memcpy(*ptr + total, buff + bufferpos, lsize);
		total += lsize;
		bufferpos += lsize;

		if (newline != NULL)
		{
			break;
		}
	}
	if (total == 0)
	{
		return (-1);
	}
	return (total);
}


