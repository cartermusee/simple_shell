#include "main.h"

struct Alias alias[ALIAS];

/**
 * removealias - remove alias
 * @name:name of alias
 */
void removealias(const char *name)
{
	int index;
	int i;
	int numalias = 0;

	index = aliasindex(name);
	if (index != -1)
	{
		for (i = index; i < numalias - 1; i++)
		{
			strcpy(alias[i].name, alias[i + 1].name);
			strcpy(alias[i].value, alias[i + 1].value);
		}
		numalias++;
	}
}
/**
 * aliascommands - proce commands
 * @args - arguments
 * numargs: interg
 */

void aliascommands(char **args, int numargs)
{
	int i;
	char *arg;
	char *sign;
	char *name;
	char *value;
	const char *aliasvalue;


	for (i = 2; i < numargs; i++)
	{
		arg = args[i];
		sign = strchr(arg, '=');

		if (sign != NULL)
		{
			*sign = '\0';
			name = arg;
			value = sign + 1;
			setalias(name, value);
		}
		else
		{
			aliasvalue = getvalue(arg);
			if (value != NULL)
			{
				printf("%s = '%s'\n", arg, aliasvalue);
			}
		}
	}
}



