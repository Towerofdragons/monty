#ifndef MONTY_H
#define MONTY_H


#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define BUFF_SIZE 50
extern char **cmd_list;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

FILE *get_stream(char *filename);
void tokenize_command(char *command);
void function_select(stack_t **stack, int line_number);

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void push(stack_t **stack, unsigned int line_number);

/*Fail functions*/
void malloc_fail(void);
#endif
