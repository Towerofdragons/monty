#include "monty.h"

char **cmd_list;

void tokenize_command(char *command)
{
	
	int idx;
	int words;
	
	idx = 0;
	words = 1;
	while (command[idx] != '\0')
	{
		if (command[idx] == ' ' && command[idx] != ' ')
			words++;
		idx++;
	}

	cmd_list = malloc(sizeof(char *) * (words + 1));
	
	if (cmd_list == NULL)
	{
		malloc_fail();
	}

	cmd_list[words + 1] = NULL;
	cmd_list[0] = &command[0];
	idx = 0;
	words = 1;
	while (command[idx] != '\0')
	{
		if (command[idx] == ' ' && command[idx +1] != ' ')
		{
			cmd_list[words] = &command[idx + 1];
			command[idx] = '\0';
			words++;	
		}
		idx++;
	}
	printf("TOKENIZED!\n");
}
