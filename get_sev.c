#include "main.h"
/**
 * _setenv - setenv function
 * @name:name of variable
 * @value:variable value
 * overwrite - integer 
 * Return:zero
 */
int  _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		fprintf(stderr, "invalid environment variable\n");
		return (-1);
	}
	if (value == NULL)
	{
		fprintf(stderr, "invalid environment value\n");
		return (-1);
	}
	if (setenv(name, value, overwrite) != 0)
	{
		perror("setnev erroe");
		return (-1);
	}
	return (0);
}
/**
 * _unsetenv - unset function
 * @name:varibale name
 * Return:zero
 */
int _unsetenv(const char *name)
{
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		fprintf(stderr, "invalid var name\n");
		return (-1);
	}
	if (unsetenv(name) != 0)
	{
		perror("unsetenv error");
		return (-1);
	}
	return (0);
}
