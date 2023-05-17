#include "main.h"

int main (void)
{
	char *str = NULL;
	size_t n = 0;
	char *prompt = "#cisfun$ ";
	char nread;
	
	int isstdfile = !isatty(fileno(stdin));
	while (1)
	{
		if (!isstdfile)
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

		printf("%s",str);
		if (isstdfile)
		{
			printf("%s\n", prompt);
		}
	}
	return (0);
}

