#include "main.h"
/**
 * _directory - function which gets direc
 * @path:pointer to path
 * Return:zero
 */
int _directory(const char *path)
{
	char wd[1024];
	const char *dir;

	if (path == NULL || strcmp(path, "-") == 0)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "unable to change to home directory\n");
			return (-1);
		}
		if (chdir(dir) != 0)
		{
			perror("chdir failed");
			return (-1);
		}
	}
	else
	{
		if (chdir(path) != 0)
		{
			perror("chdir failed");
			return (-1);
		}
	}
	if (getcwd(wd, sizeof(wd)) == NULL)
	{
		perror("due to getcwd");
		return (-1);
	}
	_setenv("PWD", wd, 1);

	return (0);
}
