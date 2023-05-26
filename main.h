#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 2400
#define ALIAS 1024
#define ALIAS_LENGTH 1024

struct Alias {
	char name[ALIAS_LENGTH];
	char value[ALIAS_LENGTH];
};
extern char **environ;
void get_env(void);
char *getpath();
char *getfullpath(char *filename, char *path);
void _path(char *filename, char **args);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void _cd(char *direc);
void directorychange(char *direc);
#endif
