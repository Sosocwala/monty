#include "monty.h"

/* ---monty_funcs--- */

/**
 * read_lines - 
 *
 * @stack:
 */

void read_lines(stack_t **stack)
{
	char *line;
	size_t line_size = 0;
	ssize_t chars = 0;
	unsigned int line_num = 1;
	void (*op_func)(stack_t **, unsigned int);
	int status;

	while (chars != -1)
	{
		line = NULL;
		chars = getline(&line, &line_size, bytecode.file);
		bytecode.line = line;
		line_num++;

		status = set_global_opcode(line);
		if (status == 0 || bytecode.op[0] == '#')
			continue;

		op_func = get_op_func(bytecode.op);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_num, bytecode.op);
			fclose(bytecode.file);
			free(bytecode.line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}

		op_func(stack, line_num);	
		free(line);
	}

	if (fclose(bytecode.file) == -1)
		exit(-1);
}

/**
 * get_op_func - 
 * @str: string to compare to existing opcode
 *
 */

void (*get_op_func(char *str)) (stack_t **, unsigned int)
{
	int i;

	instruction_t instructions[] = {
		{"push", monty_push},
		{"pall", monty_pall},
	/*	{"pint", monty_pint},
		{"pop", monty_pop},*/
		{"swap", monty_swap},
	/*	{"add", monty_add},*/
		{"nop", monty_nop},
	/*	{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},*/
		{NULL, NULL}
	};


	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
			return (instructions[i].f);
		
		i++;
	}

	return (NULL);
}

/**
 * is_number - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}

		if (isdigit(str[i]) == 0)
			return (0);

		i++;
	}

	return (1);
}

/**
 * set_global_opcode - split a line for the opcode and its argument
 *
 * @line: the line to split
 * @line_number: the current line number
 *
 * Return: returns the opcode or null on failure
 */
int set_global_opcode(char *line)
{
	char *token;

	if (line == NULL)
		return (0);

	/* get opcode 'op' command and its integer argument */
	token = strtok(line, " \n\t\r");
	bytecode.op = token;

	if (token)
	{
		token = strtok(NULL, " \n\t\r");
		bytecode.arg = token;
	}
	else
		return (0);

	return (1);
}
