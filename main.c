#include "monty.h"

/* global var should be head to struct*/

/*TODO:
 * Interpreter: 
 * function selector
 * set structure at initiation*/


int main(int argc, char **argv)
{
	char *command;
	FILE *file;
	stack_t **stack;
	size_t buff_size = BUFF_SIZE;
	int read;
	int line;

	/*int i;*/

	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr ,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = get_stream(argv[1]);
	
	
	head = NULL;
	stack = &head;
	line = 1;
	while ((read = getline(&command, &buff_size, file)) != -1)
	{
		if (read == 0)
		{
			printf("EOF\n");
			break;
		}
	/*printf("This line is:\n %s\n", command);*/

		tokenize_command(command);
		/*i = 0;
		while (cmd_list[i] != NULL)
		{
			printf("%s\n",cmd_list[i]);
			i++;
		}*/

		function_select(stack, line);
		line++;
		free(cmd_list);
	}

	fclose(file);
	return (0);

}

FILE * get_stream(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", filename);
                exit(EXIT_FAILURE);
        }
	return(file);

}
