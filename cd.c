#include "main.h"
/**
 * directorychange - changes directory
 * @direc:directory path
 */
void directorychange(char *direc)
{
	char currentdir[1024];

	if (!direc)
	{
		direc = getenv("HOME");
	}
	else if (!strcmp(direc, "-"))
	{
		direc = getenv("OLDPWD");
	}
	if (!direc)
	{
		fprintf(stderr, "cd:directory not there\n");
		return;
	}
	if (chdir(direc))
	{
		perror("error cd");
		return;
	}
	if (!getcwd(currentdir, sizeof(currentdir)))
	{
		perror("error due to cd");
		return;
	}
	if (setenv("OLDPWD", getenv("PWD"), 1) || setenv("PWD", currentdir, 1))
	{
		perror("error");
	}
}

/**
 * _cd - cals change directory
 * @direc:directory
 */

void _cd(char *direc)
{
	directorychange(direc);
}

