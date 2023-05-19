#include "main.h"
/**
 * get_env - handles the environment
 *
 **/
void get_env(void)
{
	char **environment = environ;

	while (*environment != NULL)
	{
		printf("%s\n", *environment);
		environment++;
	}

}
