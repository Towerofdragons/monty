#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (cmd_list[1] == NULL) /*TODO: check if arg is int*/
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node ==  NULL)
	{
		malloc_fail();
	}
	
	new_node -> prev = NULL;
	new_node -> n = atoi(cmd_list[1]);

	if (*stack == NULL)
	{
		new_node -> next = NULL;
	}
	else
	{
		new_node -> next = *stack;
		(*stack) -> prev = new_node;
	}
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *curr;
	curr = *stack;
	while (curr != NULL)
	{
		printf("%i\n", curr -> n);
		curr = curr -> next;
	}
}
