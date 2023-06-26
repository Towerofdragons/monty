#include "monty.h"


void function_select(stack_t **stack, int line_number)
{
	int idx;
	char *cmd;

	instruction_t instruct_list[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};

	idx = 0;
	cmd = cmd_list[0];
	while (1)
	{
		if (instruct_list[idx].opcode == NULL)
                {
                        fprintf(stderr, "L%i: unknown instruction %s\n", line_number,cmd_list[0]);
                        exit(EXIT_FAILURE);
                }

		if (strcmp(instruct_list[idx].opcode, cmd) == 0)
		{
			instruct_list[idx].f(stack, line_number);
			break;
		}
		idx++;
	}
}
