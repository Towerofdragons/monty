#include "monty.h"


void function_select(stack_t **stack, int line_number)
{
	int idx;

	instruction_t instruct_list[] = {
		{"push", &push},
		{NULL, NULL}
	};

	idx = 0;
	while (instruct_list[idx].opcode != NULL)
	{
		if (strcmp(instruct_list[idx].opcode, cmd_list[0]) == 0)
		{
			instruct_list[idx].f(stack, line_number);
		}
		idx++;
	}
}
