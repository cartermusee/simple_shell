#include  "main.h"

struct Alias alias[ALIAS];

/**
 * printalias - print alias
 *
 */

void printalias(void)
{
	int i;
	int numalias = 0;

	for (i = 0; i < numalias; i++)
	{
		printf("%s = '%s'\n", alias[i].name, alias[i].value);
	}
}
/**
 * aliasindex - find the index by name
 * @name:pointer to name
 * Return: minus one
 */

int aliasindex(const char *name)
{
	int i;
	int numalias = 0;

	for (i = 0; i < numalias; i++)
	{
		if (strcmp(alias[i].name, name) == 0)
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * getvalue - gets alias value
 * @name: name of value
 * Return:null
 */

const char *getvalue(const char *name)
{
	int index;

	index = aliasindex(name);
	if (index != -1)
	{
		return (alias[index].value);
	}
	return (NULL);
}
/**
 * setalias - sets alias
 * @name:name of alias
 * @value:value of alias
 */

void setalias(const char *name, const char *value)
{
	int index;
	int numalias = 0;

	index = aliasindex(name);
	if (index != -1)
	{
		strcpy(alias[index].value, value);
	}
	else
	{
		if (numalias < ALIAS)
		{
			strcpy(alias[numalias].name, name);
			strcpy(alias[numalias].value, value);
			numalias++;
		}
		else
		{
			fprintf(stderr, "alias maximum reached\n");
		}
	}
}

