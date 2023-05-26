#include "main.h"

#define MAXBUFF 1024
/**
 * mygetline - custom getline
 * @ptr:pointer to buffr
 * @n:size of buffer
 * @df:file descriptor
 * Return:returns wc
 */
ssize_t mygetline(char **ptr, size_t *n, int df)
{
	char m;
	char *buff = NULL;
	size_t buffsize = *n;
	ssize_t cw = 0;

	buff = malloc(sizeof(char) * buffsize);
	if (!buff)
	{
		perror("memory allocation error");
		return (-1);
	}
	while (1)
	{
		read(df, &m, 1);
		if (m == '\n' || m == EOF)
		{
			buff[cw] = '\0';
			break;
		}
		buff[cw] = m;
		cw++;
		if ((size_t)cw == buffsize)
		{
			buffsize = *n + buffsize;
			if (buffsize > MAXBUFF)
			{
				perror("unable to allocte");
				return (-1);
			}
			buff = fcrealloc(buff, *n, buffsize);
			if (!buff)
			{
				perror("allocation error");
				return (-1);
			}
			*n = buffsize;
		}
	}
	*ptr = buff;
	return (cw);
}
/**
 * fcrealloc - custom realloc function
 * @ptr:pointer
 * @lsize:long unsigned
 * @nsize:new size
 * Return:new ptr
 */

void *fcrealloc(void *ptr, size_t lsize, size_t nsize)
{
	void *nptr = NULL;

	if (nsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize == lsize)
	{
		return (ptr);
	}
	nptr = malloc(sizeof(char) * nsize);
	if (!nptr)
	{
		perror("allocation error");
		return (NULL);
	}
	memcpy(nptr, ptr, lsize);
	free(ptr);
	return (nptr);
}
