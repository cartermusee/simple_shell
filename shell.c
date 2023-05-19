#include "main.h"
/**
 * main - takes arguments
 * @argc: number of arg
 * @argv: argm themselves
 *
 * Return: zero
 */
int main(int argc, char **argv)
{
	char *str = NULL;
	size_t n = 0;
	char *prompt = "#cisfun$ ";
	char nread;
	char *token;
	pid_t pid;
	int status;
	int i = 1;
	char *args[MAX_ARGS] = {NULL};
	int is_file = !isatty(fileno(stdin));
	(void)argc;

	while (1)
	{
		if (!is_file)
		{
			printf("%s", prompt);
		}
		fflush(stdout);
		nread = getline(&str, &n, stdin);

		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("error due to eof");
				exit(EXIT_FAILURE);
			}
		}

		else if (nread == 0)
		{
			continue;
		}
		if (strlen(str) == 1)
		{
			continue;
		}
		str[strcspn(str, "\n")] = 0;

		args[0] = argv[0];
		token = strtok(str, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		if (i == 1)
		{
			continue;
		}
		args[i] = NULL;

		if (strcmp(args[1], "exit") == 0)
		{
			free(str);
			exit(0);
		}
		else if (strcmp(args[1], "env") == 0)
		{
			get_env();
			continue;
		}
		pid = fork();
		if (pid < 0)
		{
			perror("error due fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (access(args[1], F_OK) == 0)
			{
				execve(args[1], args + 1, NULL);
				perror("error");
				exit(EXIT_FAILURE);
			}
			else
			{
				_path(args[1], args + 1);
			}
		}
		else
		{
			wait(&status);
		}

		if (is_file)
		{
			if (str != NULL)
			{
				free(str);
				str = NULL;
			}
			exit(0);
		}
		else
		{
			if (str != NULL)
			{
				free(str);
				str = NULL;
			}
		}
	}
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (0);
}
