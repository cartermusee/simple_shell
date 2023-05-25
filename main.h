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
extern char **environ;
void get_env(void);
char *getpath();
char *getfullpath(char *filename, char *path);
void _path(char *filename, char **args);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _directory(const char *path);

#endif
