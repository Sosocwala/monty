#ifndef STACKS
#define STACKS

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

/* ---struct declarations--- */

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

/**
 * struct opcode_s - 
 * @op: the opcode instruction
 * @arg: the instruction's integer argument
 * @file: file to open
 * @line: buffer to store a line from file
 *
 * Description: carries the opcode, line and file values
 * throughout the program
 */

typedef struct bytecode_s
{
	char *op;
	char *arg;
	FILE *file;
	char *line;
} bytecode_t;

extern bytecode_t bytecode;


/* ---monty funcs--- */
void read_lines(stack_t **stack);
void (*get_op_func(char *str)) (stack_t **, unsigned int);
int set_global_opcode(char *line);
int is_number(char *str);


/* ---stack funcs--- */
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);


#endif /* STACKS */
