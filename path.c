#include "main.h"

/**
 * getpath - gets the PATH
 * Return: the path
 */

char *getpath()
{
	return (getenv("PATH"));
}

/**
 * getfullpath - function which gets the whole path
 * @filename: name of file
 * @path: the path
 * Return:zero
 *
 */

char *getfullpath(char *filename, char *path)
{
	char *fullpath = NULL;
	char *direc = strtok(path, ":");


	while (direc != NULL)
	{
		fullpath = malloc(strlen(direc) + strlen(filename) + 2);

		if (fullpath == NULL)
		{
			perror("malloc error in path allocaton");
			exit(EXIT_FAILURE);
		}
		sprintf(fullpath, "%s/%s", direc, filename);

		if (access(fullpath, F_OK) == 0)
		{
			return (fullpath);
		}
		free(fullpath);
		direc = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * path - function that gets the path
 * @filename : nem of file
 * @args: argument
 */

void path(char *filename, char **args)
{
	char *path = getpath();
	char *fullpath = getfullpath(filename, path);

	if (fullpath != NULL)
	{
		args[0] = fullpath;
		execve(fullpath, args, NULL);
		perror("execve error");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", args[-1], 1, filename);
		exit(EXIT_FAILURE);
	}
}
